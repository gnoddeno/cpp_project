#include "poker.h"
using namespace std;

void player::draw(player one, player two) {
	//Sleep(sleep_time);
	card1[curr_num] = rand() % 4;	//모양 지정
	card2[curr_num] = rand() % 13;	//숫자 지정
	if (comp_card(one, two)) {	//이미 뽑힌 카드이면 재귀
		draw(one, two);
	}
	else {	//뽑힌 카드가 아니면 
		//check[card1[curr_num]][card2[curr_num]] = true;	//카드가 뽑혔다고 저장
		drawn_card[card1[curr_num]][card2[curr_num]] = 1;	//뽑은 카드에 저장
		/*
		cout << curr_num+1 << ".";
		card_show(card1[curr_num], card2[curr_num]); //뽑은 카드 출력
		cout << ", ";
		*/
		curr_num++;	//뽑은 카드 수 ++
	}
}
bool comp_card(player& p1, player& p2) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			if ((p1.get_check(i, j) == p2.get_check(i, j)) && (p1.get_check(i, j) == 1))
				return true;
		}
	}
	return false;
}
void player::show_debug_card() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			cout << drawn_card[i][j] << ",";
		}
		cout << endl;
	}
}

void player::draw_card(player one, player two) {

	cout << name << " = ";
	while (curr_num != card_num) {
		//Sleep(200);
		draw(one, two);
	}

	/*
	int j = 0;	//풀하우스
	for (int i = 0; i < card_num - 3; ++i) {
		card1[i] = j++;
		card2[i] = 7;
		drawn_card[card1[i]][card2[i]] = true;
		card_show(card1[i], card2[i]);
	}
	int a = 1;
	for (int i = card_num - 3; i < card_num; ++i) {
		card1[i] = a++;
		card2[i] = 6;
		drawn_card[card1[i]][card2[i]] = true;
		card_show(card1[i], card2[i]);
	}
	*/
	/*
	int j = 3;	//플래시
	for (int i = 0; i < card_num; ++i) {
		card1[i] = j;
		card2[i] = rand() % 13;
		drawn_card[card1[i]][card2[i]] = true;
		card_show(card1[i], card2[i]);
	}
	*/
	/*
	int j = 9;	// 마운틴
	for (int i = 0; i < card_num; ++i) {
		card1[i] = rand() % 4;
		card2[i] = (j++) % 13;
		drawn_card[card1[i]][card2[i]] = true;
		card_show(card1[i], card2[i]);
	}
	*/
	/*
	int j = 0;	// 백스트레이트
	for (int i = 0; i < card_num; ++i) {
		card1[i] = rand() % 4;
		card2[i] = j++;
		drawn_card[card1[i]][card2[i]] = true;
		card_show(card1[i], card2[i]);
	}
	*/
	/*
	int j = rand() % 13;	//스트레이트
	for (int i = 0; i < card_num; ++i) {
		card1[i] = rand() % 4;
		card2[i] = (j++) % 13;
		drawn_card[card1[i]][card2[i]] = true;
		card_show(card1[i], card2[i]);
	}
	*/
	/*
	int j = rand() % 13;	//트리플
	for (int i = 0; i < card_num-2; ++i) {
		card1[i] = rand() % 4;
		card2[i] = j;
		drawn_card[card1[i]][card2[i]] = true;
		card_show(card1[i], card2[i]);
	}
	for (int i = card_num - 2; i < card_num; ++i) {
		card1[i] = rand() % 4;
		card2[i] = rand() % 13;
		drawn_card[card1[i]][card2[i]] = true;
		card_show(card1[i], card2[i]);
	}
	*/
	/*	//페어
	card1[0] = 3; card2[0] = 4; drawn_card[card1[0]][card2[0]] = true;
	card1[1] = 2; card2[1] = 4; drawn_card[card1[1]][card2[1]] = true;
	card_show(card1[0], card2[0]);
	card_show(card1[1], card2[1]);
	for (int i = 2; i < card_num; ++i) {
		card1[i] = rand() % 4;
		card2[i] = rand() % 13;
		drawn_card[card1[i]][card2[i]] = true;
		card_show(card1[i], card2[i]);
	}
	*/
	/*
	int j = rand()%4;	//백스트레이트플러쉬
	for (int i = 0; i < card_num; ++i) {
		card1[i] = j;
		card2[i] = i;
		drawn_card[card1[i]][card2[i]] = true;
	}
	*/
	cout << endl;
}
void player::swap_card(int a, int b) {
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
	cout << "|";
}
void player::show_drawn_card() {
	cout << get_name() << endl;
	for (int i = 0; i < curr_num; ++i) {
		Sleep(sleep_time);
		cout << i + 1 << ".";
		card_show(card1[i], card2[i]); //뽑은 카드 출력
		cout << ", ";
	}
	cout << endl;
}
void player::show_player_card() {
	cout << get_name() << endl;
	for (int i = 0; i < curr_num; ++i) {
		Sleep(sleep_time);
		cout << i + 1 << ".";
		if (i < 2 || i == 6) {
			card_show(99, 99);
		}
		else {
			card_show(card1[i], card2[i]); //뽑은 카드 출력
		}
		cout << ", ";
	}
	cout << endl;
}