#include "poker.h"
using namespace std;


int main() {
	srand(time(NULL));
	cout << "Poker" << endl << endl;
	char a;
	cout << "P : play, E : explain, Q : quit" << endl << ">>";
	while (cin >> a) {
		if (a == 'P' || a == 'p') {
			system("cls");
			player2_play();
		}
		else if (a == 'E' || a == 'e') {
			explain_poker();
		}
		else if (a == 'Q' || a == 'q') {
			break;
		}
		else if (a == 'D' || a == 'd') {
			player p1("pike");
			player p2("ash");
			int check[4][13] = { 0, };
			for (int i = 0; i < 3; ++i) {
				p1.draw(p1, p2, check);
			}
			for (int i = 0; i < 3; ++i) {
				p2.draw(p2, p1, check);
			}
			for (int i = 0; i < 4; ++i) {
				p1.draw(p1, p2, check);
				p2.draw(p2, p1, check);
			}
			p1.show_drawn_card();
			p2.show_drawn_card();
			detect_poker(p1);
			detect_poker(p2);
			p1.show_debug_card();
			cout << endl;
			p2.show_debug_card();
		}
		cout << "P : play, E : explain, Q : quit" << endl << ">>";
	}
	return 0;

}