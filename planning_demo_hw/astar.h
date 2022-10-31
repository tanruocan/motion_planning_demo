#pragma once
#include <iostream>
#include <graphics.h>
#include <vector>
using namespace std;

constexpr auto ZXCOST = 10;//ÿ����ֱ�ߵĴ���
constexpr auto XXCOST = 14;//ÿ����б�ߵĴ���
constexpr auto MAPTYPE = 1;//��ͼ����
constexpr auto ROWS = 60;//��ͼ���� //60
constexpr auto COLS = 50;//��ͼ���� //50
constexpr auto Swidth = 600;//600
constexpr auto Sheight = 700;//700
constexpr auto ratio = 1;//��ͼ����


enum direct
{
	p_up,//��
	p_down,//��
	p_left,//��
	p_right,//��
	p_l_up,//����
	p_r_up,//����
	p_l_down,//����
	p_r_down//����
};

enum algotype
{
	Astar,
	Dijkstra,
	BestFS
};

//��ͼ��С��Ԫ����
class Point {
public:
	int row;
	int col;

	int f = 0;
	int h = 0;
	int g = 0;
};

//��ͼ
class Map {

public:
	Map();
	void showMap();
	void drawMap();
	void drawRec(int row, int col, COLORREF color = WHITE);
	void delay(int time);

public:
	int myMap[ROWS][COLS] = { 0 };
	Point beginP = { 1,1 };
	Point endP = { ROWS - 2,COLS - 2 };

	int disX = (Swidth - (COLS - 1) * ZXCOST * ratio) / 2; //��������
	int disY = (Sheight - (ROWS - 1) * ZXCOST * ratio) / 2; //������յ�
};

//�����
class treeNode {
public:
	treeNode(int col, int row);

public:
	Point pos;
	vector<treeNode*>child;
	treeNode* pParent = nullptr;
};

//������
class tree
{
public:
	tree();
	~tree();
	void updateTree();
	void showResult();
	bool isEndPoint(treeNode* point);
	bool isStartPoint(treeNode* point);
public:
	//��ͼ����
	Map map0;
	//�����
	treeNode* pRoot = nullptr;
	//��ǰ���
	treeNode* pCurrent = nullptr;
	//��ǰ�����ڽӽ��
	treeNode* pNext = nullptr;
	//openlist
	vector<treeNode*>openlist;
	//��־λ
	bool closedlist[ROWS][COLS] = { false };

	vector<treeNode*> result;//�洢��ӡ����

	int type = Astar;
	int cost = 0;
	int costFinal = 0;
	
};

class ShortestPath
{
public:
	void shortestPath();

public:
	tree tr;
};

