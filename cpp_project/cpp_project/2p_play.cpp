#include "poker.h"
using namespace std;
void player2_play() {
	player p1("player1");
	player p2("player2");
	for (int i = 0; i < 4; ++i) {
		p1.draw(p1, p2);
		p2.draw(p2, p1);
	}
	cout << p1.get_name() << " �� ���Դϴ�." << endl;
	p1.show_drawn_card();
	p1.fall_card();
	p1.show_drawn_card();
	p1.choice_see_card();
	cout << endl;
	char a;
	cout << "���� �ѱ���� enter�� �Է��ϼ���";
	rewind(stdin);
	while (cin.get(a)) {
		if (a == '\n') {
			system("cls");
			break;
		}
		else
			continue;
	}
	cout << p2.get_name() << " �� ���Դϴ�." << endl;
	p2.show_drawn_card();
	p2.fall_card();
	p2.show_drawn_card();
	p2.choice_see_card();
	cout << endl;
	cout << "���� �ѱ���� enter�� �Է��ϼ���";
	rewind(stdin);
	while (cin.get(a)) {
		if (a == '\n') {
			system("cls");
			break;
		}
		else
			continue;
	}
	int curr = 0;
	while (curr != 4) {
		cout << p1.get_name() << " �� ���Դϴ�." << endl;
		p1.draw(p1, p2);
		p2.show_player_card();
		p1.show_drawn_card();
		cout << "���� �ѱ���� enter�� �Է��ϼ���";
		rewind(stdin);
		while (cin.get(a)) {
			if (a == '\n') {
				system("cls");
				break;
			}
			else
				continue;
		}
		cout << p2.get_name() << " �� ���Դϴ�." << endl;
		p2.draw(p2, p1);
		p1.show_player_card();
		p2.show_drawn_card();

		cout << "���� �ѱ���� enter�� �Է��ϼ���";
		rewind(stdin);
		while (cin.get(a)) {
			if (a == '\n') {
				system("cls");
				break;
			}
			else
				continue;
		}
		curr++;
	}
	detect_poker(p1);
	detect_poker(p2);
	int winner;
	cout << endl;
	poker_rank();
	cout << endl;
	cout << "1." << p1.get_name() << endl;
	cout << "2." << p2.get_name() << endl;
	while (1) {
		cout << "������ ��ȣ�� �Է����ּ��� : ";
		cin >> winner;
		if (winner == 1) {
			system("cls");
			cout << "���ڴ�" << p1.get_name() << "�Դϴ�. �������ּ���!";
			break;
		}
		else if (winner == 2) {
			system("cls");
			cout << "���ڴ�" << p2.get_name() << "�Դϴ�. �������ּ���!";
			break;
		}
	}
}
void player::fall_card() { //ó�� 4���� ī�带 �̾� ������ ī�带 ������ �ڵ�
	int number;
	while (1) {
		cout << endl << "���� ī�带 ����ּ��� >> ";
		cin >> number;
		if (5 > number > 0)
			break;
	}
	swap_card(number - 1, 3);
	curr_num--;

}
void player::choice_see_card() { // ó�� ������ ī�带 �����ϴ� �ڵ�
	int number;
	while (1) {
		cout << endl << "������ ī�带 �������ּ��� >> ";
		cin >> number;
		if (4 > number > 0)
			break;
	}
	swap_card(number - 1, 2);
}