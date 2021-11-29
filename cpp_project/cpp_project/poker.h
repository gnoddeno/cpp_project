#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <algorithm>
#define card_num 7	//총 플레이카드는 7장
#define sleep_time 200 //sleep 시간

using namespace std;
//static bool check[4][13] = { false, };	//처음 아무 카드도 뽑히지 않았으므로 0으로 초기화
typedef struct detect_card {	//족보 카드 출력을 위한 구조체
	short	int card1;
	short	int card2;
}detect_card;

class player {
	int card1[card_num];	//카드의 모양
	int card2[card_num];	//카드의 숫자
	int drawn_card[4][13] = { 0, };	//뽑은 카드 (처음엔 아무것도 뽑지 않았기 때문에 0으로 초기화)
	string name;	//플레이어의 이름
	int curr_num = 0;	//카드의 개수
	int money;	//플레이어의 소지금
public:
	player(string name, int money = 50000) { this->name = name; this->money = money; }	//플레이어의 이름 저장
	string get_name() { return name; }	//플레이어의 이름 return
	int get_money() { return money; }	//플레이어의 소지금 return
	int betting(int standard);	//베팅함수
	void bet_end(int total);	//베팅이 끝나면 동작하는 함수
	void draw(int check[4][13]);	//카드를 뽑는 함수
	void card_show(int i, int j);	//뽑은 카드를 show
	void show_drawn_card();	//플레이어가 뽑은 카드를 출력
	void show_player_card();	//상대 플레이어가 뽑은 카드를 출력하는 코드
	void swap_card(int a, int b);	//카드의 위치를 변경하는 함수(fall_card(), choice_see_card()에서 사용)
	void fall_card();	//카드를 한장 버리는 함수
	void choice_see_card();	//상대방에게 보일 카드를 한장 고르는 함수
	void show_debug_card();	//debug
	void reset_game();	// 카드를 초기화하는 코드

	friend void detect_poker(player one);	//카드의 족보를 비교하는 함수이다.
	friend bool royal_straight_flush(player one);	//로얄 스트레이트 플러시 비교
	friend bool back_straight_flush(player one);	//백 스트레이트 플러시 비교
	friend bool straight_flush(player one);	//스트레이트 플러시 비교
	friend bool four_card(player one);	//포카드 비교
	friend bool full_house(player one);	//풀하우스 비교
	friend bool flush(player one);	//플러시 비교
	friend bool mountain(player one);	//마운틴 비교
	friend bool back_straight(player one);	//백 스트레이트 비교
	friend bool straight(player one);	//스트레이트 비교
	friend bool triple(player one);	//트리플 비교
	friend bool two_pair(player one);	//원페어, 투페어 비교
	friend bool one_pair(player one);	//원페어, 투페어 비교
};
void player2_play();	// 2인 플레이
void player3_play();	// 3인 플레이
bool comp_card(int a, int b, int check[4][13]);	// 중복되는 카드를 비교
void turn_end();	// 턴을 종료시킬 때 사용
void explain_poker();	// 포커 내용 소개
void poker_rank();	// 포커의 간단한 족보 출력

