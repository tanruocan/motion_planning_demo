//#include "astar.h"
//
//Map::Map()
//{
//	//设置障碍物
//	if (MAPTYPE == 0)
//	{
//		for (int i = 0; i < ROWS; i++)
//		{
//			for (int j = 0; j < COLS; j++)
//			{
//				if (j == 20 && i <= 40)
//				{
//					myMap[i][j] = 1;
//				}
//			}
//		}
//	}
//
//	if (MAPTYPE == 1)
//	{
//		for (int i = 0; i < ROWS; i++)
//		{
//			for (int j = 0; j < COLS; j++)
//			{
//				if (j == 4 && i != 6)
//				{
//					myMap[i][j] = 1;
//				}
//
//				if (j == 12 && i != 20)
//				{
//					myMap[i][j] = 1;
//				}
//
//				if (j == 20 && i != 40)
//				{
//					myMap[i][j] = 1;
//				}
//
//				if (j == 35 && i != 20)
//				{
//					myMap[i][j] = 1;
//				}
//
//				if (i == 4 && j >= 2 && j <= 4)
//				{
//					myMap[i][j] = 1;
//				}
//
//				if (i == 3 && j >= 1 && j <= 2)
//				{
//					myMap[i][j] = 1;
//				}
//
//				if (i == ROWS - 10 && j >= COLS - 10 && j < COLS)
//				{
//					myMap[i][j] = 1;
//				}
//			}
//		}
//	}
//	else if (MAPTYPE == 2)
//	{
//		for (int i = 0; i < ROWS; i++)
//		{
//			for (int j = 0; j < COLS; j++)
//			{
//				if (j == 3 && i >= 0 && i <= 10)
//				{
//					myMap[i][j] = 1;
//				}
//
//				if (j == 5 && i != 7 && i != 6)
//				{
//					myMap[i][j] = 1;
//				}
//
//				if (j == 11 && i >= 0 && i <= 25)
//				{
//					myMap[i][j] = 1;
//				}
//
//				if (j == COLS - 9 && i >= ROWS - 16)
//				{
//					myMap[i][j] = 1;
//				}
//
//				if (i == 40 && j >= 13 && j < COLS)
//				{
//					myMap[i][j] = 1;
//				}
//
//				if (i == 30 && j >= 5 && j <= 40)
//				{
//					myMap[i][j] = 1;
//				}
//			}
//		}
//	}
//	else if (MAPTYPE == 3)
//	{
//		for (int i = 0; i < ROWS; i++)
//		{
//			for (int j = 0; j < COLS; j++)
//			{
//				if (j == 10 && (i >= 0 && /*i <= 20 || i >= 23 &&*/ i <= 50))
//				{
//					myMap[i][j] = 1;
//				}
//
//				if (j == 30 && (i >= 10 && /*i <= 50 || i >= 53 &&*/ i < ROWS))
//				{
//					myMap[i][j] = 1;
//				}
//			}
//		}
//	}
//
//	showMap();
//	drawMap();
//}
//
//void Map::showMap()
//{
//	cout << "起点位置:(" << beginP.row << "," << beginP.col << ") ,终点位置: (" << endP.row << "," << endP.col << ")" << endl;
//	myMap[beginP.row][beginP.col] = 2;
//	myMap[endP.row][endP.col] = 9;
//
//	for (int i = 0; i < ROWS; ++i)
//	{
//		for (int j = 0; j < COLS; ++j)
//		{
//			cout << myMap[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//
//void Map::drawMap()
//{
//	setbkcolor(WHITE);    //设置背景颜色
//	setlinecolor(BLACK);    //设置边框颜色
//	setlinestyle(PS_SOLID, 2);	// 设置线的样式为实线2px
//	cleardevice();//使用当前背景色清空绘图设备
//
//	for (int i = 0; i < ROWS; ++i)
//	{
//		for (int j = 0; j < COLS; ++j)
//		{
//			if (myMap[i][j] == 1)
//			{
//				drawRec(i, j, BROWN);
//			}
//			else if (myMap[i][j] == 2)
//			{
//				drawRec(i, j, RED);
//			}
//			else if (myMap[i][j] == 9)
//			{
//				drawRec(i, j, BLUE);
//
//			}else
//			{
//				drawRec(i, j);
//			}
//		}
//	}
//}
//
//void Map::drawRec(int row, int col, COLORREF color)
//{
//	setfillcolor(color);//设置填充颜色
//
//	int pointX = disX + col * ZXCOST * ratio;//X对应列
//	int pointY = disY + row * ZXCOST * ratio;//Y对应行
//
//	int left = pointX - ZXCOST / 2 * ratio;
//	int top = pointY - ZXCOST / 2 * ratio;
//	//int left = pointX;
//	//int top = pointY;
//	int right = left + ZXCOST * ratio;
//	int bottom = top + ZXCOST * ratio;
//
//	fillrectangle(left, top, right, bottom);
//}
//
//void Map::delay(int time)
//{
//	clock_t now = clock();
//	while (clock() - now < time)
//	{
//
//	}
//}
//treeNode::treeNode(int row,int col)
//{
//	pos.col = col;
//	pos.row = row;
//}
//
//tree::tree()
//{
//	pRoot = new treeNode(map0.beginP.row, map0.beginP.col);
//	closedlist[map0.beginP.row][map0.beginP.col] = true;
//	cout << "根节点:(" << pRoot->pos.row << "," << pRoot->pos.col << ")" << endl;
//
//	pCurrent = pRoot;
//}
//
//tree::~tree()
//{
//	if (pRoot != nullptr)
//	{
//		delete pRoot;
//		pRoot = nullptr;
//	}
//	if (pNext != nullptr)
//	{
//		delete pNext;
//		pNext = nullptr;
//	}
//}
//
//void tree::updateTree()
//{
//	//整个寻路过程
//	while (true)
//	{
//		BeginBatchDraw();
//
//		for (int i = 0; i < 8; ++i)
//		{
//			pNext = new treeNode(pCurrent->pos.row, pCurrent->pos.col);
//
//			switch (i)
//			{
//			case p_up:
//			{
//				pNext->pos.row--;
//				pNext->pos.g += ZXCOST;
//				break;
//			}
//			case p_down:
//			{
//				pNext->pos.row++;
//				pNext->pos.g += ZXCOST;
//				break;
//			}
//			case p_left:
//			{
//				pNext->pos.col--;
//				pNext->pos.g += ZXCOST;
//				break;
//			}
//			case p_right:
//			{
//				pNext->pos.col++;
//				pNext->pos.g += ZXCOST;
//				break;
//			}
//			case p_l_up:
//			{
//				pNext->pos.row--;
//				pNext->pos.col--;
//				pNext->pos.g += XXCOST;
//				break;
//			}
//			case p_r_up:
//			{
//				pNext->pos.row--;
//				pNext->pos.col++;
//				pNext->pos.g += XXCOST;
//				break;
//			}
//			case p_l_down:
//			{
//				pNext->pos.row++;
//				pNext->pos.col--;
//				pNext->pos.g += XXCOST;
//				break;
//			}
//			case p_r_down:
//			{
//				pNext->pos.row++;
//				pNext->pos.col++;
//				pNext->pos.g += XXCOST;
//				break;
//			}
//			default:
//				break;
//			}
//
//			//判断是否超出边界
//			if (pNext->pos.row < 0 || pNext->pos.row >= ROWS || pNext->pos.col < 0 || pNext->pos.col >= COLS)
//			{
//				cout << "超出地图边界" << endl;
//				continue;
//			}
//
//			//判断是否为障碍物以及是否已经寻找过
//			if (map0.myMap[pNext->pos.row][pNext->pos.col] == 1 || closedlist[pNext->pos.row][pNext->pos.col])
//			{
//				continue;
//			}
//
//			//计算h
//			int X = abs(pNext->pos.row - map0.endP.row);
//			int Y = abs(pNext->pos.col - map0.endP.col);
//			pNext->pos.h = (X + Y) * ZXCOST;
//
//			//计算f值
//			if (type == Astar)
//			{
//				pNext->pos.f = cost + pNext->pos.h;//Astar算法，这里g只能表示单步的代价值，而cost才是从起点到该点的累计代价值
//			}
//			else if (type == Dijkstra)
//			{
//				pNext->pos.f = cost;//Dijkstra算法
//			}
//			else if (type == BestFS)
//			{
//				pNext->pos.f = pNext->pos.h;//最佳优先算法
//			}
//
//			pCurrent->child.push_back(pNext);
//			pNext->pParent = pCurrent;
//
//			//判断是否重复，然后收入到openlist
//			bool flag = false;
//			for (auto iter = openlist.begin(); iter != openlist.end(); iter++)
//			{
//				if ((*iter)->pos.row == pNext->pos.row && (*iter)->pos.col == pNext->pos.col)
//				{
//					flag = true;//防止重复存入相同的点
//					break;
//				}
//			}
//			if (!flag)
//			{
//				openlist.push_back(pNext);//存入openList数组中，用于寻找最小f的点
//			}
//		}
//		//从openlist找到f最小的点
//		auto itmin = openlist.begin();
//		for (auto it = openlist.begin(); it != openlist.end(); it++)
//		{
//			if ((*it)->pos.f < (*itmin)->pos.f)
//			{
//				itmin = it;
//			}
//		}
//		pCurrent = *itmin;
//		closedlist[pCurrent->pos.row][pCurrent->pos.col] = true;
//		map0.myMap[pCurrent->pos.row][pCurrent->pos.col] = 5;
//		cost += (*itmin)->pos.g;
//		cout << "f值最小的点是：(" << (*itmin)->pos.row << ", " << (*itmin)->pos.col << "), f=" << (*itmin)->pos.f << ", g=" << (*itmin)->pos.g << ", h=" << (*itmin)->pos.h << ", 累计代价是：" << cost << endl;
//		itmin = openlist.erase(itmin);
//
//		//画图
//		//如果是重点
//		if (isEndPoint(pCurrent))
//		{
//			cout << "到达终点" << endl;
//			showResult();
//			break;
//		}
//		else
//		{
//			map0.drawRec(pCurrent->pos.row, pCurrent->pos.col, YELLOW);
//		}
//
//		if (openlist.empty())//判断是否走完了整个地图
//		{
//			cout << "没有找到终点" << endl << endl;
//			break;//走完了整个地图都没找到终点，也退出while循环
//		}
//		EndBatchDraw();
//		
//	}
//}
//
////显示结果
//void tree::showResult()
//{
//	while (pCurrent)
//	{
//		BeginBatchDraw();//这个函数用于开始批量绘图。执行后，任何绘图操作都将暂时不输出到绘图窗口上，直到执行 FlushBatchDraw 或 EndBatchDraw 才将之前的绘图输出。
//		result.insert(result.begin(), pCurrent);
//		costFinal += pCurrent->pos.g;
//
//		if (!isStartPoint(pCurrent) && !isEndPoint(pCurrent))
//		{
//			map0.myMap[pCurrent->pos.row][pCurrent->pos.col] = 6;
//			map0.drawRec(pCurrent->pos.row, pCurrent->pos.col, GREEN);
//		}
//		pCurrent = pCurrent->pParent;
//		EndBatchDraw();
//	}
//	map0.showMap();
//
//	string typeName;
//	if (type == Astar)
//	{
//		typeName = "Astar";
//	}
//	else if (type == Dijkstra)
//	{
//		typeName = "Dijkstra";
//	}
//	else if (type == BestFS)
//	{
//		typeName = "BestFS";
//	}
//	cout << typeName << "算法求得的最短路径是：" << endl;
//	for (auto it = result.begin(); it != result.end(); it++)
//	{
//		cout << "(" << (*it)->pos.row << ", " << (*it)->pos.col << ")";
//		if (!isEndPoint(*it))//不是终点就打印箭头
//		{
//			cout << " -> ";
//		}
//	}
//	cout << endl;
//
//	cout << "总路径长度是：" << costFinal << endl;
//}
//
//bool tree::isStartPoint(treeNode* point)
//{
//	if (point->pos.col == map0.beginP.col && point->pos.row == map0.beginP.row)
//	{
//		return true;
//	}
//	return false;
//}
//
//bool tree::isEndPoint(treeNode* point)
//{
//	if (point->pos.col == map0.endP.col && point->pos.row == map0.endP.row)
//	{
//		return true;
//	}
//	return false;
//
//}
//
//
//void ShortestPath::shortestPath()
//{
//	system("pause");
//	tr.updateTree();
//}
//
//int main()
//{
//	initgraph(Swidth, Sheight, EW_SHOWCONSOLE);
//	
//	ShortestPath sPath;
//	sPath.shortestPath();
//
//	system("pause");
//	closegraph();
//	return 0;
//
//}