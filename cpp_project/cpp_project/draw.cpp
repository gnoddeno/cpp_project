#include "poker.h"
using namespace std;

void player::draw_card(){
	//for (int i = 0; i < card_num; ++i) {
	//	card1[i] = rand() % 4;
	//	card2[i] = rand() % 13;
	//	if (check[card1[i]][card2[i]] == 1)
	//		i -= 1;
	//	else {
	//		check[card1[i]][card2[i]] = true;
	//		drawn_card[card1[i]][card2[i]] = true;
	//		card_show(card1[i], card2[i]);
	//		Sleep(200);
	//	}
	//}
	//cout << endl;

	/*int j = 0;	//풀하우스
	for (int i = 0; i < card_num - 3; ++i) {
		card1[i] = j++;
		card2[i] = 7;
		drawn_card[card1[i]][card2[i]] = true;
	}
	int a = 1;
	for (int i = card_num - 3; i < card_num; ++i) {
		card1[i] = a++;
		card2[i] = 6;
		drawn_card[card1[i]][card2[i]] = true;
	}
	*/
	/*
	int j = 3;	//플래시
	for (int i = 0; i < card_num; ++i) {
		card1[i] = j;
		card2[i] = rand() % 13;
		drawn_card[card1[i]][card2[i]] = true;
	}
	*/
	/*
	int j = 9;	// 마운틴
	for (int i = 0; i < card_num; ++i) {
		card1[i] = rand() % 4;
		card2[i] = (j++) % 13;
		drawn_card[card1[i]][card2[i]] = true;
	}
	*/
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


	for (int i = 0; i < card_num; ++i) {
		card_show(card1[i], card2[i]);
	}

}	

void player::card_show(int i, int j) {
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