#include "poker.h"
void detect_poker(player one) {	//족보가 높은순으로 비교
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
	else if (two_pair(one))
		cout << "two_pair" << endl;
	else if (one_pair(one))
		cout << "one_pair" << endl;
	else	//아무 족보와도 같지 않으면 no_pair 출력
		cout << "no_pair" << endl;
}
bool royal_straight_flush(player one) {	//로얄 스트레이트 플러시
	int detect;
	for (int i = 0; i < 4; ++i) {
		detect = 0;
		for (int j = 9; j < 14; ++j) {
			if (one.drawn_card[i][j % 13] == 1)
				detect++;	//5장의 카드가 모두 같은 무늬이면서 10, J, Q, K, A가 연달아 있는 경우 detect ++
		}
		if (detect == 5) {	//로얄 스트레이트 플러시 족보와 같으면
			for (int j = 9; j < 14; ++j) {
				one.card_show(i, j % 13);
			}
			return true;	//true 리턴
		}
	}
	return false;	//비같지 않으면 false 리턴
}
bool back_straight_flush(player one) {	//백 스트레이트 플러시
	for (int i = 0; i < 4; ++i) {
		int detect = 0;
		for (int j = 0; j < 5; ++j) {
			if (one.drawn_card[i][j] == 1)
				detect ++ ;	//5장의 카드가 모두 같은 무늬이면서 A, 2, 3, 4, 5가 연달아 있는 경우 detect++
		}
		if (detect == 5)	//백 스트레이트 플러시 족보와 같으면
			return true;	//true 리턴	
	}
	return false;	//같지 않으면 false 리턴
}
bool straight_flush(player one) {	//스트레이트 플러시
	int detect;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			detect = 0;
			for (int k = j; k < j + 5; ++k) {
				if (one.drawn_card[i][k%13] == 1)
					detect++;	//5장의 카드가 모두 같은 무늬이면서 연속된 숫자로 되어 있는 경우 detect++
			}
			if (detect == 5) {	//스트레이트 플러시 족보와 같으면
				for (int k = j; k < j + 5; ++k) {
					one.card_show(i, k%13);
				}
				return true;	//true 리턴
			}
		}
	}
	return false;	//같지 않으면 false 리턴
}
bool four_card(player one){	//포카드
	int detect = 0;
	for (int i = 0; i < 13; ++i) {
		detect = 0;
		for (int j = 0; j < 4; ++j) {
			if (one.drawn_card[j][i] == 1)//	4장의 카드가 같은 숫자로 되어 있을 경우 detect++
				detect++;
		}
		if (detect == 4) {	//포카드 족보와 같을 경우
			for (int j = 0; j < 4; ++j) {
				one.card_show(j, i);
			}
			return true;	//true 리턴
		}
	}
	return false;	//같지 않으면 false 리턴
}
bool full_house(player one){	//풀하우스
	short int detect[13] = { 0, };
	detect_card card[5];
	int cnt = 0;
	int temp;
	for (int i = 0; i < card_num; ++i) {	//같은 숫자 3장과 같은 숫자 2장으로 되어 있는 경우
		detect[one.card2[i]]++;	//detect++
	}
	for (int i = 0; i < 13; ++i) {
		if (detect[i] == 3) {
			for (int j = 0; j < 13; ++j) {
				if (one.card2[j] == i) {
					card[cnt].card1 = one.card1[j];
					card[cnt++].card2 = i;
				}
			}
			for (int j = 0; j < 13; ++j) {
				if (j == i)continue;
				else if (detect[j] == 2){	//풀하우스 족보와 같으면
					for (int k = 0; k < 13; ++k) {
						if (one.card2[k] == j) {
							card[cnt].card1 = one.card1[k];
							card[cnt++].card2 = j;
						}
					}
					cout << endl;
					for (int k = 0; k < 5; ++k) {
						one.card_show(card[k].card1, card[k].card2);
					}
					cout << endl;
					return true;	//true 리턴
				}
			}
		}
	}
	return false;	//아니면 false 리턴
}
bool flush(player one){	//플러시
	short int detect[4] = { 0, };
	detect_card card[card_num];
	int cnt = 0;
	for (int i = 0; i < card_num; ++i) {	//5장 카드 모양이 모두 같은 경우
		detect[one.card1[i]]++;	//detect++
	}
	for (int i = 0; i < 4; ++i) {
		if (detect[i] >= 5) {	//플러시 족보와 같으면
			for (int k = 0; k < card_num; ++k) {
				if (one.card1[k] == i) {
					card[cnt].card1 = i;
					card[cnt++].card2 = one.card2[k];
				}
			}
			for (int k = 0; k < 5; ++k) {
				one.card_show(card[k].card1, card[k].card2);
			}
			return true;	//true 리턴
		}
	}
	return false;	//아니면 false 리턴
}
bool mountain(player one){	//마운틴
	bool detect[13] = { false, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]] = true;
	}
	int cnt = 0;
	for (int i = 8; i < 13; ++i) {
		if (detect[(i + 1) % 13] == true) {	//5장의 카드의 숫자가 모양에 상관없이 10,J,Q,K,A로 연속될 경우
			cnt++;	//cnt++
		}
	}
	if (cnt == 5) {	//마운틴 족보와 같으면
		detect_card card[5];
		int temp = 0;
	for (int i = 8; i < 13; ++i) {
		for (int j = 0; j < card_num; ++j) {
			if (one.card2[j] == (i + 1) % 13) {
				card[temp].card1 = one.card1[j];
				card[temp].card2 = one.card2[j];
			}
		}
		temp++;
	}
		for (int i = 0; i < 5; ++i) {
			one.card_show(card[i].card1, card[i].card2);
		}
		return true;	//true 리턴
	}
	else
		return false;	//아니면 false 리턴
}
bool back_straight(player one){	//백 스트레이트
	bool detect[13] = { false, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]] = true;
	}
	int cnt = 0;
	for (int i = 0; i < 5; ++i) {
		if (detect[i] == true)	//5장의 카드의 숫자가 모양에 상관없이 A,2,3,4,5로 연속될 경우
			cnt++;	//cnt++
	}
	if (cnt == 5) {	//백 스트레이트 족보와 같으면
		int temp = 0;
		detect_card card[5];
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < card_num; ++j) {
				if (one.card2[j] == i) {
					card[temp].card1 = one.card1[j];
					card[temp].card2 = one.card2[j];
				}
			}
			temp++;
		}
		for (int i = 0; i < 5; ++i) {
			one.card_show(card[i].card1, card[i].card2);
		}
		return true;
	}//true 리턴
	else
		return false;	//false 리턴
}
bool straight(player one){	//스트레이트
	bool detect[13] = { false, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]] = true;
	}
	for (int i = 0; i < 13; ++i) {
		int cnt = 0;
		int temp = 0;
		for (int j = i; j < i + 5; ++j) {
			if (detect[j % 13] == true) {	//5장의 카드의 숫자가 무늬에 상관없이 연속될 경우
				cnt++;	//cnt++
			}
		}
		if (cnt == 5) {	//족보가 스트레이트와 같으면
			int temp;
			int det;
			detect_card card[5];
			for (int i = 0; i < 13; ++i) {
				temp = 0;
				for (int j = i; j < i + 5; ++j) {
					det = 0;
					for (int k = 0; k < card_num; ++k) {
						if (one.card2[k] == j % 13) {
							card[temp].card1 = one.card1[k];
							card[temp].card2 = one.card2[k];
							det = 1;
						}
					}
					if(det == 1)
						temp++;
					if (temp == 5) {
						for (int k = 0; k < 5; ++k) {
							one.card_show(card[k].card1, card[k].card2);
						}
						return true;	//true 리턴
					}
				}

			}
		}
	}
	return false;	//false 리턴
}
bool triple(player one){	//트리플
	char detect[13] = { 0, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]]++;	//3장의 카드의 숫자가 같은 경우 (모양 상관 없음) detect++
	}
	for (int i = 0; i < 13; ++i) {
		if (detect[i] == 3) {	//트리플 족보와 같으면
			detect_card card[3];
			int temp = 0;
			while(temp != 3){
				for (int j = 0; j < card_num; ++j) {
					if (one.card2[j] == i) {
						card[temp].card1 = one.card1[j];
						card[temp++].card2 = one.card2[j];
					}
				}
			}
		for (int j = 0; j < 3; ++j) {
			one.card_show(card[j].card1, card[j].card2);
		}
			return true;	//true 리턴
		}
	}
	return false;	//같지않으면 false 리턴
}
bool two_pair(player one){	//투페어
	char detect[13] = { 0, };
	int det[4] = { 20, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]]++;	//카드의 숫자에 맞는 배열에 +1을 해줌
	}
	int cnt = 0;
	for (int i = 0; i < 13; ++i) {
		if (detect[i] == 2) {
			det[cnt++] = i;
		}//페어가 발견되면 cnt++
	}
	detect_card card[4];
	if (cnt >= 2) {	//투페어일 경우
		int temp = 0;
		for (int i = 0; i < card_num; ++i) {
			if (one.card2[i] == det[0]) {
				card[temp].card1 = one.card1[i];
				card[temp].card2 = one.card2[i];
				temp++;
			}
		}
		for (int i = 0; i < card_num; ++i) {
			if (one.card2[i] == det[1]) {
				card[temp].card1 = one.card1[i];
				card[temp].card2 = one.card2[i];
				temp++;
			}
		}
		for (int i = 0; i < temp; ++i) {
			one.card_show(card[i].card1, card[i].card2);
		}
		return true;
	}
	return false;	//아무것도 없는 경우 false return
}
bool one_pair(player one) {	//투페어
	char detect[13] = { 0, };
	int det[4] = { 20, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]]++;	//카드의 숫자에 맞는 배열에 +1을 해줌
	}
	int cnt = 0;
	for (int i = 0; i < 13; ++i) {
		if (detect[i] == 2) {
			det[cnt++] = i;
		}//페어가 발견되면 cnt++
	}
	detect_card card[4];
	if (cnt == 1) {	//원페어일 경우
		int temp = 0;
		for (int i = 0; i < card_num; ++i) {
			if (one.card2[i] == det[0]) {
				card[temp].card1 = one.card1[i];
				card[temp].card2 = one.card2[i];
				temp++;
			}
		}
		for (int i = 0; i < temp; ++i) {
			one.card_show(card[i].card1, card[i].card2);
		}
		return true;	//1 return
	}
	else return false;
}