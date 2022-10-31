#pragma once
#include <iostream>
#include <graphics.h>
#include <vector>
using namespace std;

constexpr auto ZXCOST = 10;//每步走直线的代价
constexpr auto XXCOST = 14;//每步走斜线的代价
constexpr auto MAPTYPE = 1;//地图类型
constexpr auto ROWS = 60;//地图行数 //60
constexpr auto COLS = 50;//地图列数 //50
constexpr auto Swidth = 600;//600
constexpr auto Sheight = 700;//700
constexpr auto ratio = 1;//绘图比例


enum direct
{
	p_up,//上
	p_down,//下
	p_left,//左
	p_right,//右
	p_l_up,//左上
	p_r_up,//右上
	p_l_down,//左下
	p_r_down//右下
};

enum algotype
{
	Astar,
	Dijkstra,
	BestFS
};

//地图最小单元：点
class Point {
public:
	int row;
	int col;

	int f = 0;
	int h = 0;
	int g = 0;
};

//地图
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

	int disX = (Swidth - (COLS - 1) * ZXCOST * ratio) / 2; //网格的起点
	int disY = (Sheight - (ROWS - 1) * ZXCOST * ratio) / 2; //网格的终点
};

//树结点
class treeNode {
public:
	treeNode(int col, int row);

public:
	Point pos;
	vector<treeNode*>child;
	treeNode* pParent = nullptr;
};

//建立树
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
	//地图对象
	Map map0;
	//根结点
	treeNode* pRoot = nullptr;
	//当前结点
	treeNode* pCurrent = nullptr;
	//当前结点的邻接结点
	treeNode* pNext = nullptr;
	//openlist
	vector<treeNode*>openlist;
	//标志位
	bool closedlist[ROWS][COLS] = { false };

	vector<treeNode*> result;//存储打印数据

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

