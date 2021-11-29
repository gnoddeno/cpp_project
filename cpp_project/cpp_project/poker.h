#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <algorithm>
#define card_num 7	//�� �÷���ī��� 7��
#define sleep_time 200 //sleep �ð�

using namespace std;
//static bool check[4][13] = { false, };	//ó�� �ƹ� ī�嵵 ������ �ʾ����Ƿ� 0���� �ʱ�ȭ
typedef struct detect_card {	//���� ī�� ����� ���� ����ü
	short	int card1;
	short	int card2;
}detect_card;

class player {
	int card1[card_num];	//ī���� ���
	int card2[card_num];	//ī���� ����
	int drawn_card[4][13] = { 0, };	//���� ī�� (ó���� �ƹ��͵� ���� �ʾұ� ������ 0���� �ʱ�ȭ)
	string name;	//�÷��̾��� �̸�
	int curr_num = 0;	//ī���� ����
	int money;	//�÷��̾��� ������
public:
	player(string name, int money = 50000) { this->name = name; this->money = money; }	//�÷��̾��� �̸� ����
	string get_name() { return name; }	//�÷��̾��� �̸� return
	int get_money() { return money; }	//�÷��̾��� ������ return
	int betting(int standard);	//�����Լ�
	void bet_end(int total);	//������ ������ �����ϴ� �Լ�
	void draw(int check[4][13]);	//ī�带 �̴� �Լ�
	void card_show(int i, int j);	//���� ī�带 show
	void show_drawn_card();	//�÷��̾ ���� ī�带 ���
	void show_player_card();	//��� �÷��̾ ���� ī�带 ����ϴ� �ڵ�
	void swap_card(int a, int b);	//ī���� ��ġ�� �����ϴ� �Լ�(fall_card(), choice_see_card()���� ���)
	void fall_card();	//ī�带 ���� ������ �Լ�
	void choice_see_card();	//���濡�� ���� ī�带 ���� ���� �Լ�
	void show_debug_card();	//debug
	void reset_game();	// ī�带 �ʱ�ȭ�ϴ� �ڵ�

	friend void detect_poker(player one);	//ī���� ������ ���ϴ� �Լ��̴�.
	friend bool royal_straight_flush(player one);	//�ξ� ��Ʈ����Ʈ �÷��� ��
	friend bool back_straight_flush(player one);	//�� ��Ʈ����Ʈ �÷��� ��
	friend bool straight_flush(player one);	//��Ʈ����Ʈ �÷��� ��
	friend bool four_card(player one);	//��ī�� ��
	friend bool full_house(player one);	//Ǯ�Ͽ콺 ��
	friend bool flush(player one);	//�÷��� ��
	friend bool mountain(player one);	//����ƾ ��
	friend bool back_straight(player one);	//�� ��Ʈ����Ʈ ��
	friend bool straight(player one);	//��Ʈ����Ʈ ��
	friend bool triple(player one);	//Ʈ���� ��
	friend bool two_pair(player one);	//�����, ����� ��
	friend bool one_pair(player one);	//�����, ����� ��
};
void player2_play();	// 2�� �÷���
void player3_play();	// 3�� �÷���
bool comp_card(int a, int b, int check[4][13]);	// �ߺ��Ǵ� ī�带 ��
void turn_end();	// ���� �����ų �� ���
void explain_poker();	// ��Ŀ ���� �Ұ�
void poker_rank();	// ��Ŀ�� ������ ���� ���

