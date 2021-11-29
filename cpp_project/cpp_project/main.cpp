#include "poker.h"
using namespace std;


int main() {
	srand(time(NULL));

	    cout << "  _____  ______  __      __ _______  __   __     ______        _____    ____    _  __   ______   _____	" << endl;
		cout << "/ ____ | | ____| \\ \\    / / |  ____| | \\ | |     |____  |     |  __ \\  / __ \\  | |/ /  |  ____| |  __ \\	" << endl;
		cout << "| (___   | |__    \\ \\  / /  | |__    |  \\| |         / /      | |__) || |  | | | ' /   | |__    | |__) |" << endl;
		cout << "\\___   \\ | __ |    \\ \\/ /   |  __|   | . ` |        / /       |  ___/ | |  | | |  <    |   __|  |  _  /	" << endl;
		cout << "____)   || |____    \\  /    | |____  | |\\  |       / /        | |     | |__| | | .  \\  | |____  | | \\ \\	" << endl;
		cout << "| _____/ |______|    \\/     |______| |_| \\_|      /_/         |_|      \\____/  |_| \\_\\ |______| |_|  \\_\\	" << endl;


	char a;
	cout << "A : 2p_play, B : 3p_play, E : explain, Q : quit" << endl << ">> ";
	while (cin >> a) {
		if (a == 'A' || a == 'a') {
			system("cls");
			player2_play();
		}
		else if (a == 'B' || a == 'b') {
			system("cls");
			player3_play();
		}
		else if (a == 'E' || a == 'e') {
			explain_poker();
		}
		else if (a == 'Q' || a == 'q') {
			break;
		}
		cout << "A : 2p_play, B : 3p_play, E : explain, Q : quit" << endl << ">> ";
	}
	return 0;
}