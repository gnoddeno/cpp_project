#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <algorithm>
#define card_num 7	//총 카드가 7장
#define init_card_num 5	//게임 방식에 대해 test 중
#define sleep_time 200 //sleep 시간

using namespace std;
static bool check[4][13] = { false, };	//처음 아무 카드도 뽑히지 않았으므로 0으로 초기화
typedef struct detect_card {
	short	int card1;
	short	int card2;
}detect_card; 

class player {
	int card1[card_num];	//카드의 모양
	int card2[card_num];	//카드의 숫자
	bool drawn_card[4][13] = { false };	//뽑은 카드 (처음엔 아무것도 뽑지 않았기 때문에 0으로 초기화)
	string name;
	int curr_num = 0;	//카드의 개수
public:
	player(string name) { this->name = name; }	//플레이어의 이름 저장
	string get_name() { return name; }	//플레이어의 이름 return
	void draw_card();	//카드 뽑기
	void b_draw();	//가장 기본이 되는 draw
	void a_draw();
	void card_show(int i, int j);	//뽑은 카드를 show
	void show_drawn_card();	//디버그 코드
	void swap_card(int a, int b);
	void fall_card();
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
void player2_play();	//2인 플레이 구현중
void show_check();	//디버그 함수
void explain_poker();	//포커 내용 소개

