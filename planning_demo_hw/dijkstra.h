#pragma once
#include <iostream>
#include <stack>
using namespace std;

#define MAX_VERTEX_NUM 20//��󶥵���
#define INFINITE 9999//��������
#define VRType int //Ȩֵ
#define VertexType int //�������������

class MGraph
{
public:
	VertexType vexs[MAX_VERTEX_NUM];//�洢ͼ�ж�������
	VRType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ��󣺼�¼����֮��Ĺ�ϵ
	int vexnum;
	int arcnum;
};

class Dijkstra
{
public:
	Dijkstra();//���캯��
	void CreatUDN(MGraph& G);//���������Ȩͼ
	int FindVex(MGraph& G, VertexType v);//���ݶ����ж����ڶ�ά�����ֵ�λ��
	void PrintGraph(MGraph& G);//��ӡͼ
	void ShortestPath_Dijkstra();

public:
	MGraph G;
	int V0 = 0;
	int Patharc[MAX_VERTEX_NUM];//ÿ�����㱻���ʺ��ǰ��������±꣨���׽ڵ㣩
	int Distance[MAX_VERTEX_NUM];//�洢��㵽���������·����Ȩֵ֮��
	bool isVisit[MAX_VERTEX_NUM];//�жϸýڵ��Ƿ񱻷��ʹ�
	int k;//��ʱ�±�
	int min;//��ʱ���·��
	stack<int> path;//�ѣ� ����ȳ�
};