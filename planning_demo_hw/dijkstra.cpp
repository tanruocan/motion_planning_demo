//#include "dijkstra.h"
//
//Dijkstra::Dijkstra()
//{
//	//建图
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
//	cout << "请输入顶点数" << endl;
//	cin >> v;
//	if (v > MAX_VERTEX_NUM || v <= 0)
//	{
//		cout << "顶点数输入错误，请重新输入" << endl;
//		goto reInput1;
//	}
//
//reInput2:
//	cout << "请输入边数" << endl;
//	cin >> a;
//	if (a > v * (v - 1) / 2 || a <= 0)
//	{
//		cout << "边数输入错误，请重新输入" << endl;
//		goto reInput2;
//	}
//
//	G.vexnum = v;
//	G.arcnum = a;
//
//	int vex;
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		cout << "请输入该顶点的元素： " << endl;
//		cin >> vex;
//		G.vexs[i] = vex;
//	}
//
//	//初始化矩阵，给矩阵赋值
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		for (int j = 0; j < G.vexnum; ++j)
//		{
//			G.arcs[i][j] = INFINITE;
//		}
//	}
//
//	//更新连接关系
//	for (int i = 0; i < G.arcnum; ++i)
//	{
//		VertexType v1, v2;
//		VRType w;
//		cout << "请输入要创建关系的两个顶点元素" << endl;
//		cin >> v1;
//		cin >> v2;
//		cout << "请输入这两个顶点之间的边的权重" << endl;
//		cin >> w;
//
//		int n = FindVex(G, v1);
//		int m = FindVex(G, v2);
//
//		if (n == -1 || m == -1)
//		{
//			cout << "至少有一个点不存在" << endl;
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
//	cout << "图的邻接矩阵是： " << endl;
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
//	//打印
//	cout << "Dijkstra算法求出的最短路径是：" << endl;
//	for (int i = 0; i < G.vexnum; ++i)
//	{
//		if (i != 0 && Distance[i] != INFINITE)
//		{
//			cout << "从顶点" << G.vexs[V0] << "到顶点" << G.vexs[i] << ", " << "最短路径权值为：" << Distance[i] << "，最短路径为： ";
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