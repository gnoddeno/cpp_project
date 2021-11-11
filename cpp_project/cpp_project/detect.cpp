#include "poker.h"
void detect_poker(player one) {
	cout << one.get_name() << " >> ";
	if (royal_straight_flush(one))
		cout << "royal_straight_flush " << endl;
	else if (back_straight_flush(one))
		cout << "back_straight_flush" << endl;
	else if (straight_flush(one))
		cout << "straight_flush" << endl;
	else if (four_card(one))
		cout << "four_card" << endl;
	else if (full_house(one))
		cout << "full_house" << endl;
	else if (flush(one))
		cout << "flush" << endl;
	else if (mountain(one))
		cout << "mountain" << endl;
	else if (back_straight(one))
		cout << "back_straight" << endl;
	else if (straight(one))
		cout << "straight" << endl;
	else if (triple(one))
		cout << "triple" << endl;
	else if (num_pair(one) == 2)
		cout << "two_pair" << endl;
	else if (num_pair(one) == 1)
		cout << "one_pair" << endl;
	else
		cout << "no_pair" << endl;
}
bool royal_straight_flush(player one) {
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
bool back_straight_flush(player one) {
	for (int i = 0; i < 4; ++i) {
		int cnt = 0;
		for (int j = 0; j < 5; ++j) {
			if (one.drawn_card[i][j] == 1)
				cnt ++ ;
		}
		if (cnt == 5)
			return true;
	}
	return false;
}
bool straight_flush(player one) {
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
				else if (detect[j] == 2){

					return true;
				}
			}
		}
	}
	return false;
}
bool flush(player one){
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
bool mountain(player one){
	bool detect[13] = { false, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]] = true;
	}
	int cnt = 0;
	for (int i = 8; i < 13; ++i) {
		if (detect[(i + 1) % 13] == true)
			cnt++;
	}
	if (cnt == 5)
		return true;
	else
		return false;
}
bool back_straight(player one){
	bool detect[13] = { false, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]] = true;
	}
	int cnt = 0;
	for (int i = 0; i < 5; ++i) {
		if (detect[i] == true)
			cnt++;
	}
	if (cnt == 5)
		return true;
	else
		return false;
}
bool straight(player one){
	bool detect[13] = { false, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]] = true;
	}
	for (int i = 0; i < 13; ++i) {
		int cnt = 0;
		for (int j = i; j < i + 5; ++j) {
			if (detect[j % 13] == true)
				cnt++;
		}
		if (cnt == 5)
			return true;
	}
	return false;
}
bool triple(player one){
	char detect[13] = { 0, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]]++;
	}
	for (int i = 0; i < 13; ++i) {
		if (detect[i]==3)
			return true;
	}
	return false;
}
char num_pair(player one){
	char detect[13] = { 0, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]]++;
	}
	int cnt = 0;
	for (int i = 0; i < 13; ++i) {
		if (detect[i] == 2)cnt++;
	}
	if (cnt == 1)
		return 1;
	else if (cnt >= 2)
		return 2;
	else
		return false;
}                                                     