#include "poker.h"
void player3_play() {
	string name1, name2, name3;
	int money_setting;
	cout << "플레이어 3 명의 이름을 입력해 주세요 >> ";
	cin >> name1 >> name2 >> name3;
	cout << "초기 자금을 입력해 주세요 >> ";
	cin >> money_setting;
	char a;
	player p1(name1, money_setting);
	player p2(name2, money_setting);
	player p3(name3, money_setting);
	while (1) {
		int detect1 = 0;
		int detect2 = 0;
		int detect3 = 0;

		if (p1.get_money() <= 0)
			detect1 = 1;
		else if (p2.get_money() <= 0)
			detect2 = 2;
		else if (p3.get_money() <= 0)
			detect3 = 3;

		p1.reset_game();
		p2.reset_game();
		p3.reset_game();
		int check[4][13] = { 0, };
		for (int i = 0; i < 4; ++i) {
			p1.draw(check);
			p2.draw(check);
			p3.draw(check);
		}
		system("cls");
		if(detect1 == 0){
		cout << p1.get_name() << " 의 턴입니다." << endl;
		p1.show_drawn_card();
		p1.fall_card();
		p1.show_drawn_card();
		p1.choice_see_card();
		cout << endl;

		rewind(stdin);
		turn_end();
		turn_end();
		}
		if(detect2 == 0){
		cout << p2.get_name() << " 의 턴입니다." << endl;
		p2.show_drawn_card();
		p2.fall_card();
		p2.show_drawn_card();
		p2.choice_see_card();
		cout << endl;

		rewind(stdin);
		turn_end();
		turn_end();
		}
		if(detect3 == 0){
		cout << p3.get_name() << " 의 턴입니다." << endl;
		p3.show_drawn_card();
		p3.fall_card();
		p3.show_drawn_card();
		p3.choice_see_card();
		cout << endl;

		rewind(stdin);
		turn_end();
		turn_end();
		}
		int curr = 0;
		int stand_money = 0;
		int temp = 0;
		int total_money = 0;

		while (curr != 4) {
			if (detect1 == 0) {
				if (curr != 0) {
					if (detect3 != 0)
						cout << p2.get_name();
					else
						cout << p3.get_name();
					cout << " 이 " << temp << "만큼 베팅했습니다." << endl;
				}
				cout << "total money >> " << total_money << endl;
				cout << p1.get_name() << " 의 턴입니다." << endl;
				p1.draw(check);
				if (detect2 == 0)
					p2.show_player_card();
				if (detect3 == 0)
					p3.show_player_card();
				p1.show_drawn_card();

				cout << "Betting : B, Die : D 를 입력해주세요 >> ";
				rewind(stdin);
				while (cin.get(a)) {
					if (a == 'B' || a == 'b') {
						temp = p1.betting(stand_money);
						break;
					}
					else if (a == 'D' || a == 'd') {
						detect1 = 1;
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
			}
			if (detect1 == 0 && detect2 != 0 && detect3 != 0)
				break;
			else if (detect2 == 0 && detect1 != 0 && detect3 != 0)
				break;
			else if (detect3 == 0 && detect1 != 0 && detect2 != 0)
				break;
			if (detect2 == 0) {
				if (detect1 != 0)
					cout << p3.get_name();
				else
					cout << p1.get_name();
				cout << " 이 " << temp << "만큼 베팅했습니다." << endl;
				cout << "total money >> " << total_money << endl;
				cout << p2.get_name() << " 의 턴입니다." << endl;
				p2.draw(check);
				if (detect1 == 0)
					p1.show_player_card();
				if (detect3 == 0)
					p3.show_player_card();
				p2.show_drawn_card();

				cout << "Betting : B, Die : D 를 입력해주세요 >> ";
				rewind(stdin);
				while (cin.get(a)) {
					if (a == 'B' || a == 'b') {
						temp = p2.betting(stand_money);
						break;
					}
					else if (a == 'D' || a == 'd') {
						detect2 = 2;
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
			}
			if (detect1 == 0 && detect2 != 0 && detect3 != 0)
				break;
			else if (detect2 == 0 && detect1 != 0 && detect3 != 0)
				break;
			else if (detect3 == 0 && detect1 != 0 && detect2 != 0)
				break;
			if (detect3 == 0) {
				if (detect2 != 0)
					cout << p1.get_name();
				else
					cout << p2.get_name();
				cout << " 이 " << temp << "만큼 베팅했습니다." << endl;
				cout << "total money >> " << total_money << endl;
				cout << p3.get_name() << " 의 턴입니다." << endl;
				p3.draw(check);
				if (detect1 == 0)
					p1.show_player_card();
				if (detect2 == 0)
					p2.show_player_card();
				p3.show_drawn_card();

				cout << "Betting : B, Die : D 를 입력해주세요 >> ";
				rewind(stdin);
				while (cin.get(a)) {
					if (a == 'B' || a == 'b') {
						temp = p3.betting(stand_money);
						break;
					}
					else if (a == 'D' || a == 'd') {
						detect3 = 3;
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
			}

			if (detect1 == 0 && detect2 != 0 && detect3 != 0)
				break;
			else if (detect2 == 0 && detect1 != 0 && detect3 != 0)
				break;
			else if (detect3 == 0 && detect1 != 0 && detect2 != 0)
				break;
			curr++;
		}
		if (detect1 == 0 && detect2 == 0 && detect3 == 0) {
			detect_poker(p1);
			detect_poker(p2);
			detect_poker(p3);
			int winner;
			cout << endl;
			poker_rank();
			cout << endl;
			cout << "1." << p1.get_name() << endl;
			cout << "2." << p2.get_name() << endl;
			cout << "3." << p3.get_name() << endl;
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
				else if (winner == 3) {
					system("cls");
					cout << "승자는" << p3.get_name() << "입니다. 축하해주세요!" << endl;
					p3.bet_end(total_money);
					break;
				}
			}

		}
		else if (detect1 == 0 && detect2 == 2 && detect3 == 3) {
			system("cls");
			cout << "승자는" << p1.get_name() << "입니다. 축하해주세요!";
			p1.bet_end(total_money);
		}
		else if (detect2 == 0 && detect1 == 1 && detect3 == 3) {
			system("cls");
			cout << "승자는" << p2.get_name() << "입니다. 축하해주세요!";
			p2.bet_end(total_money);
		}
		else if (detect3 == 0 && detect1 == 1 && detect2 == 2) {
			system("cls");
			cout << "승자는" << p3.get_name() << "입니다. 축하해주세요!";
			p3.bet_end(total_money);
		}

		rewind(stdin);
		if ((p1.get_money() <= 0) && (p2.get_money() <= 0))
			break;
		else if ((p2.get_money() <= 0) && (p3.get_money() <= 0))
			break;
		else if ((p1.get_money() <= 0) && (p3.get_money() <= 0))
			break;

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
	if (p1.get_money() > p2.get_money() && p1.get_money() > p3.get_money()) {
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
	else if (p2.get_money() > p1.get_money() && p2.get_money() > p3.get_money()) {
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
	else if (p3.get_money() > p1.get_money() && p3.get_money() > p2.get_money()) {
		system("cls");
		cout << "이 게임의 승자는 " << p3.get_name() << "입니다!." << endl << endl;
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