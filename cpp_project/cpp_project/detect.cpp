#include "poker.h"
void detect_poker(player one) {	//������ ���������� ��
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
	else	//�ƹ� �����͵� ���� ������ no_pair ���
		cout << "no_pair" << endl;
}
bool royal_straight_flush(player one) {	//�ξ� ��Ʈ����Ʈ �÷���
	int detect;
	for (int i = 0; i < 4; ++i) {
		detect = 0;
		for (int j = 9; j < 14; ++j) {
			if (one.drawn_card[i][j % 13] == 1)
				detect++;	//5���� ī�尡 ��� ���� �����̸鼭 10, J, Q, K, A�� ���޾� �ִ� ��� detect ++
		}
		if (detect == 5) {	//�ξ� ��Ʈ����Ʈ �÷��� ������ ������
			for (int j = 9; j < 14; ++j) {
				one.card_show(i, j % 13);
			}
			return true;	//true ����
		}
	}
	return false;	//���� ������ false ����
}
bool back_straight_flush(player one) {	//�� ��Ʈ����Ʈ �÷���
	for (int i = 0; i < 4; ++i) {
		int detect = 0;
		for (int j = 0; j < 5; ++j) {
			if (one.drawn_card[i][j] == 1)
				detect ++ ;	//5���� ī�尡 ��� ���� �����̸鼭 A, 2, 3, 4, 5�� ���޾� �ִ� ��� detect++
		}
		if (detect == 5)	//�� ��Ʈ����Ʈ �÷��� ������ ������
			return true;	//true ����	
	}
	return false;	//���� ������ false ����
}
bool straight_flush(player one) {	//��Ʈ����Ʈ �÷���
	int detect;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			detect = 0;
			for (int k = j; k < j + 5; ++k) {
				if (one.drawn_card[i][k%13] == 1)
					detect++;	//5���� ī�尡 ��� ���� �����̸鼭 ���ӵ� ���ڷ� �Ǿ� �ִ� ��� detect++
			}
			if (detect == 5) {	//��Ʈ����Ʈ �÷��� ������ ������
				for (int k = j; k < j + 5; ++k) {
					one.card_show(i, k%13);
				}
				return true;	//true ����
			}
		}
	}
	return false;	//���� ������ false ����
}
bool four_card(player one){	//��ī��
	int detect = 0;
	for (int i = 0; i < 13; ++i) {
		detect = 0;
		for (int j = 0; j < 4; ++j) {
			if (one.drawn_card[j][i] == 1)//	4���� ī�尡 ���� ���ڷ� �Ǿ� ���� ��� detect++
				detect++;
		}
		if (detect == 4) {	//��ī�� ������ ���� ���
			for (int j = 0; j < 4; ++j) {
				one.card_show(j, i);
			}
			return true;	//true ����
		}
	}
	return false;	//���� ������ false ����
}
bool full_house(player one){	//Ǯ�Ͽ콺
	short int detect[13] = { 0, };
	detect_card card[5];
	int cnt = 0;
	int temp;
	for (int i = 0; i < card_num; ++i) {	//���� ���� 3��� ���� ���� 2������ �Ǿ� �ִ� ���
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
				else if (detect[j] == 2){	//Ǯ�Ͽ콺 ������ ������
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
					return true;	//true ����
				}
			}
		}
	}
	return false;	//�ƴϸ� false ����
}
bool flush(player one){	//�÷���
	short int detect[4] = { 0, };
	detect_card card[card_num];
	int cnt = 0;
	for (int i = 0; i < card_num; ++i) {	//5�� ī�� ����� ��� ���� ���
		detect[one.card1[i]]++;	//detect++
	}
	for (int i = 0; i < 4; ++i) {
		if (detect[i] >= 5) {	//�÷��� ������ ������
			for (int k = 0; k < card_num; ++k) {
				if (one.card1[k] == i) {
					card[cnt].card1 = i;
					card[cnt++].card2 = one.card2[k];
				}
			}
			for (int k = 0; k < 5; ++k) {
				one.card_show(card[k].card1, card[k].card2);
			}
			return true;	//true ����
		}
	}
	return false;	//�ƴϸ� false ����
}
bool mountain(player one){	//����ƾ
	bool detect[13] = { false, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]] = true;
	}
	int cnt = 0;
	for (int i = 8; i < 13; ++i) {
		if (detect[(i + 1) % 13] == true) {	//5���� ī���� ���ڰ� ��翡 ������� 10,J,Q,K,A�� ���ӵ� ���
			cnt++;	//cnt++
		}
	}
	if (cnt == 5) {	//����ƾ ������ ������
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
		return true;	//true ����
	}
	else
		return false;	//�ƴϸ� false ����
}
bool back_straight(player one){	//�� ��Ʈ����Ʈ
	bool detect[13] = { false, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]] = true;
	}
	int cnt = 0;
	for (int i = 0; i < 5; ++i) {
		if (detect[i] == true)	//5���� ī���� ���ڰ� ��翡 ������� A,2,3,4,5�� ���ӵ� ���
			cnt++;	//cnt++
	}
	if (cnt == 5) {	//�� ��Ʈ����Ʈ ������ ������
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
	}//true ����
	else
		return false;	//false ����
}
bool straight(player one){	//��Ʈ����Ʈ
	bool detect[13] = { false, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]] = true;
	}
	for (int i = 0; i < 13; ++i) {
		int cnt = 0;
		int temp = 0;
		for (int j = i; j < i + 5; ++j) {
			if (detect[j % 13] == true) {	//5���� ī���� ���ڰ� ���̿� ������� ���ӵ� ���
				cnt++;	//cnt++
			}
		}
		if (cnt == 5) {	//������ ��Ʈ����Ʈ�� ������
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
						return true;	//true ����
					}
				}

			}
		}
	}
	return false;	//false ����
}
bool triple(player one){	//Ʈ����
	char detect[13] = { 0, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]]++;	//3���� ī���� ���ڰ� ���� ��� (��� ��� ����) detect++
	}
	for (int i = 0; i < 13; ++i) {
		if (detect[i] == 3) {	//Ʈ���� ������ ������
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
			return true;	//true ����
		}
	}
	return false;	//���������� false ����
}
bool two_pair(player one){	//�����
	char detect[13] = { 0, };
	int det[4] = { 20, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]]++;	//ī���� ���ڿ� �´� �迭�� +1�� ����
	}
	int cnt = 0;
	for (int i = 0; i < 13; ++i) {
		if (detect[i] == 2) {
			det[cnt++] = i;
		}//�� �߰ߵǸ� cnt++
	}
	detect_card card[4];
	if (cnt >= 2) {	//������� ���
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
	return false;	//�ƹ��͵� ���� ��� false return
}
bool one_pair(player one) {	//�����
	char detect[13] = { 0, };
	int det[4] = { 20, };
	for (int i = 0; i < card_num; ++i) {
		detect[one.card2[i]]++;	//ī���� ���ڿ� �´� �迭�� +1�� ����
	}
	int cnt = 0;
	for (int i = 0; i < 13; ++i) {
		if (detect[i] == 2) {
			det[cnt++] = i;
		}//�� �߰ߵǸ� cnt++
	}
	detect_card card[4];
	if (cnt == 1) {	//������� ���
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