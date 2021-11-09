#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <algorithm>
#define card_num 5

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
	friend void detect_poker(player one);
	friend bool royal_straight_flash(player one);
	friend bool straight_flash(player one);
	friend bool four_card(player one);
	friend bool full_house(player one);
	friend bool flash(player one);
	friend bool mountain(player one);
	friend bool back_straight(player one);
	friend bool straight(player one);
	//friend bool triple(player one);
	// friend bool two_pair(player one);
	// friend bool one_pair(player one);
};
class drawn_example:private player {
public:
	void draw_fullhouse();
};
void show_check();
void explain_poker();