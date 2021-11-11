#include"poker.h"
using namespace std;
void player2_play() {
	player p1("player1");
	p1.draw_card();
	detect_poker(p1);
}