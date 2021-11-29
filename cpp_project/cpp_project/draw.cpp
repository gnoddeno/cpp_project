#include "poker.h"
using namespace std;

void player::draw(int check[4][13]) {	//ī��̱�
	card1[curr_num] = rand() % 4;	//��� ����
	card2[curr_num] = rand() % 13;	//���� ����
	if (comp_card(card1[curr_num], card2[curr_num], check)) {	//�̹� ���� ī���̸� ���
		draw(check);
	}
	else {	//���� ī�尡 �ƴϸ� 
		check[card1[curr_num]][card2[curr_num]] = 1;	//���� ī��� ���
		drawn_card[card1[curr_num]][card2[curr_num]] = 1;	//���� ī�忡 ����
		curr_num++;	//���� ī�� �� ++
	}
}
bool comp_card(int a, int b, int check[4][13]) {	// �ߺ��Ǵ� ī�带 ��
	if (check[a][b] == 1)
		return true;
	else
		return false;
}

void player::swap_card(int a, int b) { // ī�� ���� �ٲٱ�
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
	cout << "| ";
}
void player::show_drawn_card() {	//�÷��̾ ���� ī�带 ���
	cout << endl << get_name() << setw(10) << "money : " << get_money() << endl;
	for (int i = 0; i < curr_num; ++i) {
		Sleep(sleep_time);
		cout << i + 1 << ".";
		card_show(card1[i], card2[i]); //���� ī�� ���
		cout << ", ";
	}
	cout << endl;
}
void player::show_player_card() {	//��� �÷��̾ ���� ī�带 ����ϴ� �ڵ�
	cout << endl << get_name() << setw(10) << "money : " << get_money() << endl;
	for (int i = 0; i < curr_num; ++i) {
		Sleep(sleep_time);
		cout << i + 1 << ".";
		if (i < 2 || i == 6) {	//1,2��° ī��� 7��° ����ī��
			card_show(99, 99);
		}
		else {
			card_show(card1[i], card2[i]); //���� ī�� ���
		}
		cout << ", ";
	}
	cout << endl;
}

void player::show_debug_card() {	//debug �Լ�
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			cout << drawn_card[i][j] << ",";
		}
		cout << endl;
	}
}