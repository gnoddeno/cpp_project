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
			p1.draw_card(p1, p2);
			p2.draw_card(p2, p1);
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