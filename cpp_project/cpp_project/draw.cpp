#include "poker.h"
using namespace std;

void player::draw(player one, player two) {
	//Sleep(sleep_time);
	card1[curr_num] = rand() % 4;	//��� ����
	card2[curr_num] = rand() % 13;	//���� ����
	if (comp_card(one, two)) {	//�̹� ���� ī���̸� ���
		draw(one, two);
	}
	else {	//���� ī�尡 �ƴϸ� 
		//check[card1[curr_num]][card2[curr_num]] = true;	//ī�尡 �����ٰ� ����
		drawn_card[card1[curr_num]][card2[curr_num]] = 1;	//���� ī�忡 ����
		/*
		cout << curr_num+1 << ".";
		card_show(card1[curr_num], card2[curr_num]); //���� ī�� ���
		cout << ", ";
		*/
		curr_num++;	//���� ī�� �� ++
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
	int j = 0;	//Ǯ�Ͽ콺
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
	int j = 3;	//�÷���
	for (int i = 0; i < card_num; ++i) {
		card1[i] = j;
		card2[i] = rand() % 13;
		drawn_card[card1[i]][card2[i]] = true;
		card_show(card1[i], card2[i]);
	}
	*/
	/*
	int j = 9;	// ����ƾ
	for (int i = 0; i < card_num; ++i) {
		card1[i] = rand() % 4;
		card2[i] = (j++) % 13;
		drawn_card[card1[i]][card2[i]] = true;
		card_show(card1[i], card2[i]);
	}
	*/
	/*
	int j = 0;	// �齺Ʈ����Ʈ
	for (int i = 0; i < card_num; ++i) {
		card1[i] = rand() % 4;
		card2[i] = j++;
		drawn_card[card1[i]][card2[i]] = true;
		card_show(card1[i], card2[i]);
	}
	*/
	/*
	int j = rand() % 13;	//��Ʈ����Ʈ
	for (int i = 0; i < card_num; ++i) {
		card1[i] = rand() % 4;
		card2[i] = (j++) % 13;
		drawn_card[card1[i]][card2[i]] = true;
		card_show(card1[i], card2[i]);
	}
	*/
	/*
	int j = rand() % 13;	//Ʈ����
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
	/*	//���
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
	int j = rand()%4;	//�齺Ʈ����Ʈ�÷���
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
void player::card_show(int i, int j) {	//draw�� ī�� ���


	cout << "|";
	if (i == 99 && j == 99) {
		cout << " " << setw(5) << " ";
		cout << "|";
		return;
	}
	if (i == 0)
		cout << "��";
	else if (i == 1)
		cout << "��";
	else if (i == 2)
		cout << "��";
	else if (i == 3)
		cout << "��";
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
		card_show(card1[i], card2[i]); //���� ī�� ���
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
			card_show(card1[i], card2[i]); //���� ī�� ���
		}
		cout << ", ";
	}
	cout << endl;
}