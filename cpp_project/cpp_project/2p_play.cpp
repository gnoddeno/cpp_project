#include "poker.h"
using namespace std;
void player2_play() {
	player p1("player1");
	p1.b_draw();
	p1.b_draw();
	p1.b_draw();
	p1.b_draw();
	p1.show_drawn_card();
	p1.fall_card();
	p1.b_draw();
	p1.show_drawn_card();
	cout << endl;
	show_check();
}
void player::fall_card() { 
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