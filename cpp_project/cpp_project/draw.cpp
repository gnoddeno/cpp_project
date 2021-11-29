#include "poker.h"
using namespace std;

void player::draw(int check[4][13]) {	//카드뽑기
	card1[curr_num] = rand() % 4;	//모양 지정
	card2[curr_num] = rand() % 13;	//숫자 지정
	if (comp_card(card1[curr_num], card2[curr_num], check)) {	//이미 뽑힌 카드이면 재귀
		draw(check);
	}
	else {	//뽑힌 카드가 아니면 
		check[card1[curr_num]][card2[curr_num]] = 1;	//뽑은 카드로 등록
		drawn_card[card1[curr_num]][card2[curr_num]] = 1;	//뽑은 카드에 저장
		curr_num++;	//뽑은 카드 수 ++
	}
}
bool comp_card(int a, int b, int check[4][13]) {	// 중복되는 카드를 비교
	if (check[a][b] == 1)
		return true;
	else
		return false;
}

void player::swap_card(int a, int b) { // 카드 순서 바꾸기
	int temp = 0;
	temp = card1[a];
	card1[a] = card1[b];
	card1[b] = temp;

	temp = card2[a];
	card2[a] = card2[b];
	card2[b] = temp;
}
void player::card_show(int i, int j) {	//draw한 카드 출력
	cout << "|";
	if (i == 99 && j == 99) {
		cout << " " << setw(5) << " ";
		cout << "|";
		return;
	}
	if (i == 0)
		cout << "♠";
	else if (i == 1)
		cout << "◆";
	else if (i == 2)
		cout << "♥";
	else if (i == 3)
		cout << "♣";
	if (j == 10)
		cout << setw(5) << "J";
	else if (j == 11)
		cout << setw(5) << "Q";
	else if (j == 12)
		cout << setw(5) << "K";
	else if (j == 0)
		cout << setw(5) << "A";
	else if (0 < j < 10)
		cout << setw(5) << j + 1;
	cout << "| ";
}
void player::show_drawn_card() {	//플레이어가 뽑은 카드를 출력
	cout << endl << get_name() << setw(10) << "money : " << get_money() << endl;
	for (int i = 0; i < curr_num; ++i) {
		Sleep(sleep_time);
		cout << i + 1 << ".";
		card_show(card1[i], card2[i]); //뽑은 카드 출력
		cout << ", ";
	}
	cout << endl;
}
void player::show_player_card() {	//상대 플레이어가 뽑은 카드를 출력하는 코드
	cout << endl << get_name() << setw(10) << "money : " << get_money() << endl;
	for (int i = 0; i < curr_num; ++i) {
		Sleep(sleep_time);
		cout << i + 1 << ".";
		if (i < 2 || i == 6) {	//1,2번째 카드와 7번째 히든카드
			card_show(99, 99);
		}
		else {
			card_show(card1[i], card2[i]); //뽑은 카드 출력
		}
		cout << ", ";
	}
	cout << endl;
}

void player::show_debug_card() {	//debug 함수
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			cout << drawn_card[i][j] << ",";
		}
		cout << endl;
	}
}