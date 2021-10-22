#include "poker.h"
using namespace std;


int main() {
	//explain_poker();
	int n;
	//cin >> n;
	system("cls");
	srand(time(NULL));
	cout << "Poker" << endl;
	
	player p1;
	cout << "p1" << endl;
	p1.draw_card();
	player p2;
	cout << "p2" << endl;
	p2.draw_card();
	player p3;
	cout << "p3" << endl;
	p3.draw_card();
	player p4;
	cout << "p4" << endl;
	p4.draw_card();
	//show_check();
	cout << "p1" << endl;
	p1.show_drawn_card();
	cout << "p2" << endl;
	p2.show_drawn_card();
	cout << "p3" << endl;
	p3.show_drawn_card();
	cout << "p4" << endl;
	p4.show_drawn_card();
}