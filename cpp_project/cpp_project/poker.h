#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <algorithm>
#define card_num 7	//�� ī�尡 7��
#define init_card_num 5	//���� ��Ŀ� ���� test ��
#define sleep_time 200 //sleep �ð�

using namespace std;
static bool check[4][13] = { false, };	//ó�� �ƹ� ī�嵵 ������ �ʾ����Ƿ� 0���� �ʱ�ȭ
typedef struct detect_card {
	short	int card1;
	short	int card2;
}detect_card; 

class player {
	int card1[card_num];	//ī���� ���
	int card2[card_num];	//ī���� ����
	bool drawn_card[4][13] = { false };	//���� ī�� (ó���� �ƹ��͵� ���� �ʾұ� ������ 0���� �ʱ�ȭ)
	string name;
	int curr_num = 0;	//ī���� ����
public:
	player(string name) { this->name = name; }	//�÷��̾��� �̸� ����
	string get_name() { return name; }	//�÷��̾��� �̸� return
	void draw_card();	//ī�� �̱�
	void b_draw();	//���� �⺻�� �Ǵ� draw
	void a_draw();
	void card_show(int i, int j);	//���� ī�带 show
	void show_drawn_card();	//����� �ڵ�
	void swap_card(int a, int b);
	void fall_card();
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
void player2_play();	//2�� �÷��� ������
void show_check();	//����� �Լ�
void explain_poker();	//��Ŀ ���� �Ұ�

