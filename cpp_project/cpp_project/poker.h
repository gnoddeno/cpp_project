#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#define card_num 7

using namespace std;
static bool check[4][13] = { 0, };
class player {
	int card1[card_num];
	int card2[card_num];
	bool drawn_card[4][13] = { false };
public:
	void draw_card();
	void card_show(int i, int j);
	void show_drawn_card();
};
void show_check();
void explain_poker();