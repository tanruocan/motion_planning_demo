//#include "dijkstra.h"
//
//Dijkstra::Dijkstra()
//{
//	//��ͼ
//	CreatUDN(G);
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		isVisit[i] = false;
//		Distance[i] = G.arcs[V0][i];
//		Patharc[i] = V0;
//	}
//	Distance[V0] = 0;
//	isVisit[V0] = true;
//
//	cout << endl;
//	PrintGraph(G);
//}
//void Dijkstra::CreatUDN(MGraph& G)
//{
//	int v;
//	int a;
//
//reInput1:
//	cout << "�����붥����" << endl;
//	cin >> v;
//	if (v > MAX_VERTEX_NUM || v <= 0)
//	{
//		cout << "�����������������������" << endl;
//		goto reInput1;
//	}
//
//reInput2:
//	cout << "���������" << endl;
//	cin >> a;
//	if (a > v * (v - 1) / 2 || a <= 0)
//	{
//		cout << "���������������������" << endl;
//		goto reInput2;
//	}
//
//	G.vexnum = v;
//	G.arcnum = a;
//
//	int vex;
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		cout << "������ö����Ԫ�أ� " << endl;
//		cin >> vex;
//		G.vexs[i] = vex;
//	}
//
//	//��ʼ�����󣬸�����ֵ
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		for (int j = 0; j < G.vexnum; ++j)
//		{
//			G.arcs[i][j] = INFINITE;
//		}
//	}
//
//	//�������ӹ�ϵ
//	for (int i = 0; i < G.arcnum; ++i)
//	{
//		VertexType v1, v2;
//		VRType w;
//		cout << "������Ҫ������ϵ����������Ԫ��" << endl;
//		cin >> v1;
//		cin >> v2;
//		cout << "����������������֮��ıߵ�Ȩ��" << endl;
//		cin >> w;
//
//		int n = FindVex(G, v1);
//		int m = FindVex(G, v2);
//
//		if (n == -1 || m == -1)
//		{
//			cout << "������һ���㲻����" << endl;
//			return;
//		}
//
//		G.arcs[n][m] = w;
//		G.arcs[m][n] = w;
//	}
//
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		for (int j = 0; j < G.vexnum; ++j)
//		{
//			if (i == j)
//			{
//				G.arcs[i][j] = 0;
//			}
//		}
//	}
//}
//
//int Dijkstra::FindVex(MGraph& g, VertexType v)
//{
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		if (G.vexs[i] == v)
//		{
//			return i;
//		}
//	}
//	cout << "no such vertex." << endl;
//	return -1;
//}
//
//void Dijkstra::PrintGraph(MGraph& G)
//{
//	cout << "ͼ���ڽӾ����ǣ� " << endl;
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		for (int j = 0; j < G.vexnum; ++j)
//		{
//			cout << G.arcs[i][j] << ", ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//void Dijkstra::ShortestPath_Dijkstra()
//{
//	for (int i = 1; i < G.vexnum; ++i)
//	{
//		int min = INFINITE;
//		for (int j = 0; j < G.vexnum; ++j)
//		{
//			if (!isVisit[j] && Distance[j] < min)
//			{
//				k = j;
//				min = Distance[j];
//			}
//		}
//		isVisit[k] = true;
//
//		for (int j = 0; j < G.vexnum; ++j)
//		{
//			if (!isVisit[j])
//			{
//				if (min + G.arcs[k][j] < Distance[j])
//				{
//					Distance[j] = min + G.arcs[k][j];
//					Patharc[j] = k;
//				}
//			}
//		}
//	}
//	cout << endl;
//
//	//��ӡ
//	cout << "Dijkstra�㷨��������·���ǣ�" << endl;
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		if (i != 0 && Distance[i] != INFINITE)
//		{
//			cout << "�Ӷ���" << G.vexs[V0] << "������" << G.vexs[i] << ", " << "���·��ȨֵΪ��" << Distance[i] << "�����·��Ϊ�� ";
//			int m = i;
//			while (m != 0)
//			{
//				path.push(G.vexs[m]);
//				m = Patharc[m];
//			}
//			path.push(G.vexs[V0]);
//
//			while (!path.empty())
//			{
//				if (path.size() == 1)
//				{
//					cout << path.top();
//				}
//				else {
//					cout << path.top() << "->";
//				}
//				path.pop();
//
//			}
//			cout << endl;
//
//		}
//	}
//}
//int main()
//{
//	Dijkstra D0;
//	D0.ShortestPath_Dijkstra();
//
//	system("pause");
//	return 0;
//}