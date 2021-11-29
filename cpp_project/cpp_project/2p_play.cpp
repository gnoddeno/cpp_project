#include "poker.h"
using namespace std;
void player2_play() {	//2인 플레이
	string name1, name2;
	int money_setting;
	cout << "플레이어 2 명의 이름을 입력해 주세요 >> ";
	cin >> name1 >> name2;
	cout << "초기 자금을 입력해 주세요 >> ";
	cin >> money_setting;
	char a;
	player p1(name1, money_setting);
	player p2(name2, money_setting);
	while (1) {
		int detect = 0;
		p1.reset_game();
		p2.reset_game();
		int check[4][13] = { 0, };
		for (int i = 0; i < 4; ++i) {
			p1.draw(check);
			p2.draw(check);
		}
		system("cls");
		cout << p1.get_name() << " 의 턴입니다." << endl;
		p1.show_drawn_card();
		p1.fall_card();
		p1.show_drawn_card();
		p1.choice_see_card();
		cout << endl;

		rewind(stdin);
		turn_end();
		turn_end();

		cout << p2.get_name() << " 의 턴입니다." << endl;
		p2.show_drawn_card();
		p2.fall_card();
		p2.show_drawn_card();
		p2.choice_see_card();
		cout << endl;

		rewind(stdin);
		turn_end();
		turn_end();

		int curr = 0;
		int stand_money = 0;
		int temp = 0;
		int total_money = 0;

		while (curr != 4 && detect == 0) {
			if (curr != 0)
				cout << p2.get_name() << " 이 " << temp << "만큼 베팅했습니다." << endl;
			cout << "total money >> " << total_money << endl;
			cout << p1.get_name() << " 의 턴입니다." << endl;
			p1.draw(check);
			p2.show_player_card();
			p1.show_drawn_card();

			cout << "Betting : B, Die : D 를 입력해주세요 >> ";
			rewind(stdin);
			while (cin.get(a)) {
				if (a == 'B' || a == 'b') {
					temp = p1.betting(stand_money);
					break;
				}
				else if (a == 'D' || a == 'd') {
					detect = 2;
					break;
				}
				else {
					Sleep(200);
					cout << "Betting : B, Die : D 를 입력해주세요 >> ";
					continue;
				}
			}
			rewind(stdin);
			stand_money = temp;
			total_money += stand_money;
			system("cls");
			turn_end();
			if (detect == 0) {
				cout << p1.get_name() << " 이 " << temp << "만큼 베팅했습니다." << endl;
				cout << "total money >> " << total_money << endl;
				cout << p2.get_name() << " 의 턴입니다." << endl;
				p2.draw(check);
				p1.show_player_card();
				p2.show_drawn_card();
				cout << "Betting : B, Die : D 를 입력해주세요 >> ";
				rewind(stdin);
				while (cin.get(a)) {
					if (a == 'B' || a == 'b') {
						temp = p2.betting(stand_money);
						break;
					}
					else if (a == 'D' || a == 'd') {
						detect = 1;
						break;
					}
					else {
						Sleep(200);
						cout << "Betting : B, Die : D 를 입력해주세요 >> ";
						continue;
					}
				}
				rewind(stdin);
				stand_money = temp;
				total_money += stand_money;
				system("cls");
				turn_end();
				curr++;
			}
		}
		if (detect == 0) {
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
					cout << "승자는" << p1.get_name() << "입니다. 축하해주세요!" << endl;
					p1.bet_end(total_money);
					break;
				}
				else if (winner == 2) {
					system("cls");
					cout << "승자는" << p2.get_name() << "입니다. 축하해주세요!" << endl;
					p2.bet_end(total_money);
					break;
				}
			}
		}
		else if (detect == 1) {
			system("cls");
			cout << "승자는" << p1.get_name() << "입니다. 축하해주세요!";
			p1.bet_end(total_money);
		}
		else if (detect == 2) {
			system("cls");
			cout << "승자는" << p2.get_name() << "입니다. 축하해주세요!";
			p2.bet_end(total_money);
		}
		rewind(stdin);
		if ((p1.get_money() <= 0) || (p2.get_money() <= 0)) {
			break;
		}
		cout << "계속 진행하려면 enter를, 그만하려면 b를 입력해 주세요" << endl;
		while (cin.get(a)) {
			if (a == '\n') {
				break;
			}
			else if (a == 'B' || a == 'b') {
				break;
			}
		}
		if (a == 'B' || a == 'b')
			break;
	}
	if (p1.get_money() > p2.get_money()) {
		system("cls");
		cout << "이 게임의 승자는 " << p1.get_name() << "입니다!." << endl << endl;
		cout << " __     __  ______   ______   ________   ______   _______   __      __ " << endl;
		cout << "/  |   /  |/      | /      | /        | /      | /       | /  |    /  |" << endl;
		cout << "$$ |   $$ |$$$$$$/ /$$$$$$  |$$$$$$$$/ /$$$$$$  |$$$$$$$  |$$  |  /$$/ " << endl;
		cout << "$$ |   $$ |  $$ |  $$ |  $$/    $$ |   $$ |  $$ |$$ |__$$ | $$  |/$$/  " << endl;
		cout << "$$  | /$$/   $$ |  $$ |         $$ |   $$ |  $$ |$$    $$<   $$  $$/   " << endl;
		cout << " $$  /$$/    $$ |  $$ |   __    $$ |   $$ |  $$ |$$$$$$$  |   $$$$/    " << endl;
		cout << "  $$ $$/    _$$ |_ $$ |__/  |   $$ |   $$ |__$$ |$$ |  $$ |    $$ |    " << endl;
		cout << "   $$$/    / $$   |$$    $$/    $$ |   $$    $$/ $$ |  $$ |    $$ |    " << endl;
		cout << "    $/     $$$$$$/  $$$$$$/     $$/     $$$$$$/  $$/   $$/     $$/     " << endl;
		Sleep(2000);
	}
	else if (p2.get_money() > p1.get_money()) {
		system("cls");
		cout << "이 게임의 승자는 " << p2.get_name() << "입니다!." << endl << endl;
		cout << " __     __  ______   ______   ________   ______   _______   __      __ " << endl;
		cout << "/  |   /  |/      | /      | /        | /      | /       | /  |    /  |" << endl;
		cout << "$$ |   $$ |$$$$$$/ /$$$$$$  |$$$$$$$$/ /$$$$$$  |$$$$$$$  |$$  |  /$$/ " << endl;
		cout << "$$ |   $$ |  $$ |  $$ |  $$/    $$ |   $$ |  $$ |$$ |__$$ | $$  |/$$/  " << endl;
		cout << "$$  | /$$/   $$ |  $$ |         $$ |   $$ |  $$ |$$    $$<   $$  $$/   " << endl;
		cout << " $$  /$$/    $$ |  $$ |   __    $$ |   $$ |  $$ |$$$$$$$  |   $$$$/    " << endl;
		cout << "  $$ $$/    _$$ |_ $$ |__/  |   $$ |   $$ |__$$ |$$ |  $$ |    $$ |    " << endl;
		cout << "   $$$/    / $$   |$$    $$/    $$ |   $$    $$/ $$ |  $$ |    $$ |    " << endl;
		cout << "    $/     $$$$$$/  $$$$$$/     $$/     $$$$$$/  $$/   $$/     $$/     " << endl;
		Sleep(2000);
	}
}
void player::bet_end(int total) {	//베팅이 끝나면 동작하는 함수
	cout << get_name() << "가 상금" << total << "을 가져갑니다!" << endl;
	money += total;
}

int player::betting(int standard) {	//베팅함수
	int bet_money;
	cout << "배팅 할 금액을 입력해 주세요(최소 배팅금액은 " << standard << ") >> ";
	while (cin >> bet_money) {
		if (standard <= bet_money) {
			money -= bet_money;
			break;
		}
		cout << "배팅 할 금액을 입력해 주세요(최소 배팅금액은 " << standard << ") >>";
	}
	return bet_money;
}

void turn_end() {	// 턴을 종료시킬 때 사용
	char a;
	cout << "턴을 넘기려면 enter를 입력하세요";
	while (cin.get(a)) {
		if (a == '\n') {
			system("cls");
			break;
		}
		else
			continue;
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
void player::reset_game() {	// 카드를 초기화하는 코드
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			drawn_card[i][j] = 0;
		}
	}
	curr_num = 0;
}