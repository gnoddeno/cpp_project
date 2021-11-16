#include "poker.h"
using namespace std;

void player::draw() {
	card1[curr_num] = rand() % 4;	//모양 지정
	card2[curr_num] = rand() % 13;	//숫자 지정
	if (check[card1[curr_num]][card2[curr_num]] == true)	//이미 뽑힌 카드이면 재귀
		draw();
	else {	//뽑힌 카드가 아니면
		check[card1[curr_num]][card2[curr_num]] = true;	//카드가 뽑혔다고 저장
		drawn_card[card1[curr_num]][card2[curr_num]] = true;	//뽑은 카드에 저장
		card_show(card1[curr_num], card2[curr_num]); //뽑은 카드 출력
		curr_num++;	//뽑은 카드 수 ++
	}
}
void player::draw_card(){
	/*
	cout << name << " = ";
	while (curr_num != card_num) {
		Sleep(40);
		draw();
	}
	
	*/
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
	
	int j = 9;	// 마운틴
	for (int i = 0; i < card_num; ++i) {
		card1[i] = rand() % 4;
		card2[i] = (j++) % 13;
		drawn_card[card1[i]][card2[i]] = true;
		card_show(card1[i], card2[i]);
	}
	
	/*
	int j = 0;	// 백스트레이트
	for (int i = 0; i < card_num; ++i) {
		card1[i] = rand() % 4;
		card2[i] = j++;
		drawn_card[card1[i]][card2[i]] = true;
	}
	*/
	/*
	int j = rand() % 13;	//스트레이트
	for (int i = 0; i < card_num; ++i) {
		card1[i] = rand() % 4;
		card2[i] = (j++) % 13;
		drawn_card[card1[i]][card2[i]] = true;
	}
	*/
	/*
	int j = rand() % 13;	//트리플
	for (int i = 0; i < card_num-2; ++i) {
		card1[i] = rand() % 4;
		card2[i] = j;
		drawn_card[card1[i]][card2[i]] = true;
	}
	for (int i = card_num - 2; i < card_num; ++i) {
		card1[i] = rand() % 4;
		card2[i] = rand() % 13;
		drawn_card[card1[i]][card2[i]] = true;
	}
	*/
	/*	//페어
	card1[0] = 3; card2[0] = 4; drawn_card[card1[0]][card2[0]] = true;
	card1[1] = 2; card2[1] = 4; drawn_card[card1[1]][card2[1]] = true;
	for (int i = 2; i < card_num; ++i) {
		card1[i] = rand() % 4;
		card2[i] = rand() % 13;
		drawn_card[card1[i]][card2[i]] = true;
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

void player::card_show(int i, int j) {	//draw한 카드 출력
	cout << "|";
	if (i == 0)
		cout << "♠";
	else if (i == 1)
		cout << "◆";
	else if (i == 2)
		cout << "♥";
	else
		cout << "♣";
	if (j == 10)
		cout << setw(5) << "J";
	else if (j == 11)
		cout << setw(5) << "Q";
	else if (j == 12)
		cout << setw(5) << "K";
	else if (j == 0)
		cout << setw(5) << "A";
	else
		cout << setw(5) << j + 1;
	cout << "|";
}
void player::show_drawn_card() {
	for (int i = 0; i < 4; ++i ){
		for (int j = 0; j < 13; ++j) {
			cout << drawn_card[i][j]<< ", ";
		}
		cout << endl;
	}
}


void show_check() {
	for (int k = 0; k < 4; ++k) {
		for (int l = 0; l < 13; ++l) {
			cout << check[k][l] << ", ";
		}
		cout << endl;
	}
}