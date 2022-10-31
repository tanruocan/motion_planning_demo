#pragma once
#include <iostream>
#include <stack>
using namespace std;

#define MAX_VERTEX_NUM 20//最大顶点数
#define INFINITE 9999//无穷大的数
#define VRType int //权值
#define VertexType int //顶点的数据类型

class MGraph
{
public:
	VertexType vexs[MAX_VERTEX_NUM];//存储图中顶点数据
	VRType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵：记录顶点之间的关系
	int vexnum;
	int arcnum;
};

class Dijkstra
{
public:
	Dijkstra();//构造函数
	void CreatUDN(MGraph& G);//构造无向带权图
	int FindVex(MGraph& G, VertexType v);//根据顶点判断其在二维数组种的位置
	void PrintGraph(MGraph& G);//打印图
	void ShortestPath_Dijkstra();

public:
	MGraph G;
	int V0 = 0;
	int Patharc[MAX_VERTEX_NUM];//每个顶点被访问后的前驱顶点的下标（父亲节点）
	int Distance[MAX_VERTEX_NUM];//存储起点到各个点最短路径的权值之和
	bool isVisit[MAX_VERTEX_NUM];//判断该节点是否被访问过
	int k;//临时下标
	int min;//临时最短路径
	stack<int> path;//堆： 后进先出
};