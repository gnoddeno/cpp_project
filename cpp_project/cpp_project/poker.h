#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <algorithm>
#define card_num 7
#define init_card_num 8

using namespace std;
static bool check[4][13] = { 0, };
class player {
	int card1[card_num];
	int card2[card_num];
	bool drawn_card[4][13] = { false };
	string name;
	int curr_num = 0;
public:
	player(string name) { this->name = name; }
	string get_name() { return name; }
	void draw_card();
	void draw();
	void card_show(int i, int j);
	void show_drawn_card();
	friend void detect_poker(player one);
	friend bool royal_straight_flush(player one);
	friend bool back_straight_flush(player one);
	friend bool straight_flush(player one);
	friend bool four_card(player one);
	friend bool full_house(player one);
	friend bool flush(player one);
	friend bool mountain(player one);
	friend bool back_straight(player one);
	friend bool straight(player one);
	friend bool triple(player one);
	friend char num_pair(player one);

};
void player2_play();

void show_check();
void explain_poker();

