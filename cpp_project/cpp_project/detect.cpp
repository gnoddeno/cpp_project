#include "poker.h"
void detect_poker(player one) {
	if (royal_straight_flash(one))
		cout << endl << "royal_straight_flash " << endl;
	else if (straight_flash(one))
		cout << endl << "straight_flash" << endl;
	else if (four_card(one))
		cout << endl << "four_card" << endl;
	else if (full_house(one))
		cout << endl << "full_house" << endl;
	else if (flash(one))
		cout << endl << "flash" << endl;
	else
		cout << "no_pair" << endl;
}
bool royal_straight_flash(player one) {
	int detect;
	for (int i = 0; i < 4; ++i) {
		detect = 0;
		for (int j = 9; j < 14; ++j) {
			if (one.drawn_card[i][j % 13] == 1)
				detect++;
		}
		if (detect == 5) {
			for (int j = 9; j < 14; ++j) {
				one.card_show(i, j % 13);
			}
			return true;
		}
	}
	return false;
}
bool straight_flash(player one) {
	int detect;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			detect = 0;
			for (int k = j; k < j + 5; ++k) {
				if (one.drawn_card[i][k%13] == 1)
					detect++;
			}
			if (detect == 5) {
				for (int k = j; k < j + 5; ++k) {
					one.card_show(i, k%13);
				}
				return true;
			}
		}
	}
	return false;
}
bool four_card(player one){
	int detect = 0;
	for (int i = 0; i < 13; ++i) {
		detect = 0;
		for (int j = 0; j < 4; ++j) {
			if (one.drawn_card[j][i] == 1)
				detect++;
		}
		if (detect == 4) {
			for (int j = 0; j < 4; ++j) {
				one.card_show(j, i);
			}
			return true;
		}
	}
	return false;
}
bool full_house(player one){
	short int detect[13] = { 0, };
	int temp;
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]]++;
	}
	for (int i = 0; i < 13; ++i) {
		if (detect[i] == 3) {
			for (int j = 0; j < 13; ++j) {
				if (j == i)continue;
				else if (detect[j] == 2)
					return true;
			}
		}
	}
	return false;
}
bool flash(player one){
	short int detect[4] = { 0, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card1[i]]++;
	}
	for (int i = 0; i < card_num; ++i) {
		if (detect[one.card1[i]] == 5)
			return true;
	}
	return false;
}
// bool mountain(player one){}
// bool back_straight(player one){}
// bool straight(player one){}
// bool triple(player one){}
// bool two_pair(player one){}
// bool one_pair(player one){}