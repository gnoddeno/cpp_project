#include "poker.h"
using namespace std;
void player2_play() {
	player p1("player1");
	player p2("player2");
	for (int i = 0; i < 4; ++i) {
		p1.draw(p1, p2);
		p2.draw(p2, p1);
	}
	cout << p1.get_name() << " 의 턴입니다." << endl;
	p1.show_drawn_card();
	p1.fall_card();
	p1.show_drawn_card();
	p1.choice_see_card();
	cout << endl;
	char a;
	cout << "턴을 넘기려면 enter를 입력하세요";
	rewind(stdin);
	while (cin.get(a)) {
		if (a == '\n') {
			system("cls");
			break;
		}
		else
			continue;
	}
	cout << p2.get_name() << " 의 턴입니다." << endl;
	p2.show_drawn_card();
	p2.fall_card();
	p2.show_drawn_card();
	p2.choice_see_card();
	cout << endl;
	cout << "턴을 넘기려면 enter를 입력하세요";
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
		cout << p1.get_name() << " 의 턴입니다." << endl;
		p1.draw(p1, p2);
		p2.show_player_card();
		p1.show_drawn_card();
		cout << "턴을 넘기려면 enter를 입력하세요";
		rewind(stdin);
		while (cin.get(a)) {
			if (a == '\n') {
				system("cls");
				break;
			}
			else
				continue;
		}
		cout << p2.get_name() << " 의 턴입니다." << endl;
		p2.draw(p2, p1);
		p1.show_player_card();
		p2.show_drawn_card();

		cout << "턴을 넘기려면 enter를 입력하세요";
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
		cout << "승자의 번호를 입력해주세요 : ";
		cin >> winner;
		if (winner == 1) {
			system("cls");
			cout << "승자는" << p1.get_name() << "입니다. 축하해주세요!";
			break;
		}
		else if (winner == 2) {
			system("cls");
			cout << "승자는" << p2.get_name() << "입니다. 축하해주세요!";
			break;
		}
	}
}
void player::fall_card() { //처음 4장의 카드를 뽑아 한장의 카드를 버리는 코드
	int number;
	while (1) {
		cout << endl << "버릴 카드를 골라주세요 >> ";
		cin >> number;
		if (5 > number > 0)
			break;
	}
	swap_card(number - 1, 3);
	curr_num--;

}
void player::choice_see_card() { // 처음 보여질 카드를 선택하는 코드
	int number;
	while (1) {
		cout << endl << "보여질 카드를 선택해주세요 >> ";
		cin >> number;
		if (4 > number > 0)
			break;
	}
	swap_card(number - 1, 2);
}