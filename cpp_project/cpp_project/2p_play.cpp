#include "poker.h"
using namespace std;
void player2_play() {
	player p1("player1");
	//player p2("player2");
	//player p3("player3");
	p1.draw_card();
	//p2.draw_card();
	//p3.draw_card();
	detect_poker(p1);
	//detect_poker(p2);
	//detect_poker(p3);
}