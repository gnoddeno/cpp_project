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
	int j = 0;
	for (int i = 0; i < card_num-1; ++i) {
		card1[i] = j++;
		card2[i] = 7;
		drawn_card[card1[i]][card2[i]] = true;
	}
	card1[4] = rand() % 4;
	card2[4] = rand() % 13;
	drawn_card[card1[4]][card2[4]] = true;
	for (int i = 0; i < card_num; ++i) {
		card_show(card1[i], card2[i]);
	}

}	

void player::card_show(int i, int j) {
	cout << "|";
	if (i == 0)
		cout << "¢¼";
	else if (i == 1)
		cout << "¡ß";
	else if (i == 2)
		cout << "¢¾";
	else
		cout << "¢À";
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