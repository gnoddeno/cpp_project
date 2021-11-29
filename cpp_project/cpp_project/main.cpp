#include "poker.h"
using namespace std;


int main() {
	srand(time(NULL));
	cout << R"(  
   __ __     __      ___   __  __     __ __  
  (_ |_ \  /|_ |\ |    /  |__)/  \|_/|_ |__) 
  __)|__ \/ |__| \|   /   |   \__/| \|__|  \  )" << endl << endl;
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