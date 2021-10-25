#include "poker.h"
void detect_poker(player one) {
	if (royal_straight_flash(one))
		cout << endl << "royal_straight_flash " << endl;
	else if (straight_flash(one))
		cout << endl << "straight_flash" << endl;
	else if (four_card(one))
		cout << endl << "four_card" << endl;
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
// bool full_house(player one){}
// bool flash(player one){}
// bool mountain(player one){}
// bool back_straight(player one){}
// bool straight(player one){}
// bool triple(player one){}
// bool two_pair(player one){}
// bool one_pair(player one){}