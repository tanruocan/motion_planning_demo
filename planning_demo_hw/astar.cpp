//#include "astar.h"
//
//Map::Map()
//{
//	//�����ϰ���
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
//	cout << "���λ��:(" << beginP.row << "," << beginP.col << ") ,�յ�λ��: (" << endP.row << "," << endP.col << ")" << endl;
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
//	setbkcolor(WHITE);    //���ñ�����ɫ
//	setlinecolor(BLACK);    //���ñ߿���ɫ
//	setlinestyle(PS_SOLID, 2);	// �����ߵ���ʽΪʵ��2px
//	cleardevice();//ʹ�õ�ǰ����ɫ��ջ�ͼ�豸
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
//	setfillcolor(color);//���������ɫ
//
//	int pointX = disX + col * ZXCOST * ratio;//X��Ӧ��
//	int pointY = disY + row * ZXCOST * ratio;//Y��Ӧ��
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
//	cout << "���ڵ�:(" << pRoot->pos.row << "," << pRoot->pos.col << ")" << endl;
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
//	//����Ѱ·����
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
//			//�ж��Ƿ񳬳��߽�
//			if (pNext->pos.row < 0 || pNext->pos.row >= ROWS || pNext->pos.col < 0 || pNext->pos.col >= COLS)
//			{
//				cout << "������ͼ�߽�" << endl;
//				continue;
//			}
//
//			//�ж��Ƿ�Ϊ�ϰ����Լ��Ƿ��Ѿ�Ѱ�ҹ�
//			if (map0.myMap[pNext->pos.row][pNext->pos.col] == 1 || closedlist[pNext->pos.row][pNext->pos.col])
//			{
//				continue;
//			}
//
//			//����h
//			int X = abs(pNext->pos.row - map0.endP.row);
//			int Y = abs(pNext->pos.col - map0.endP.col);
//			pNext->pos.h = (X + Y) * ZXCOST;
//
//			//����fֵ
//			if (type == Astar)
//			{
//				pNext->pos.f = cost + pNext->pos.h;//Astar�㷨������gֻ�ܱ�ʾ�����Ĵ���ֵ����cost���Ǵ���㵽�õ���ۼƴ���ֵ
//			}
//			else if (type == Dijkstra)
//			{
//				pNext->pos.f = cost;//Dijkstra�㷨
//			}
//			else if (type == BestFS)
//			{
//				pNext->pos.f = pNext->pos.h;//��������㷨
//			}
//
//			pCurrent->child.push_back(pNext);
//			pNext->pParent = pCurrent;
//
//			//�ж��Ƿ��ظ���Ȼ�����뵽openlist
//			bool flag = false;
//			for (auto iter = openlist.begin(); iter != openlist.end(); iter++)
//			{
//				if ((*iter)->pos.row == pNext->pos.row && (*iter)->pos.col == pNext->pos.col)
//				{
//					flag = true;//��ֹ�ظ�������ͬ�ĵ�
//					break;
//				}
//			}
//			if (!flag)
//			{
//				openlist.push_back(pNext);//����openList�����У�����Ѱ����Сf�ĵ�
//			}
//		}
//		//��openlist�ҵ�f��С�ĵ�
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
//		cout << "fֵ��С�ĵ��ǣ�(" << (*itmin)->pos.row << ", " << (*itmin)->pos.col << "), f=" << (*itmin)->pos.f << ", g=" << (*itmin)->pos.g << ", h=" << (*itmin)->pos.h << ", �ۼƴ����ǣ�" << cost << endl;
//		itmin = openlist.erase(itmin);
//
//		//��ͼ
//		//������ص�
//		if (isEndPoint(pCurrent))
//		{
//			cout << "�����յ�" << endl;
//			showResult();
//			break;
//		}
//		else
//		{
//			map0.drawRec(pCurrent->pos.row, pCurrent->pos.col, YELLOW);
//		}
//
//		if (openlist.empty())//�ж��Ƿ�������������ͼ
//		{
//			cout << "û���ҵ��յ�" << endl << endl;
//			break;//������������ͼ��û�ҵ��յ㣬Ҳ�˳�whileѭ��
//		}
//		EndBatchDraw();
//		
//	}
//}
//
////��ʾ���
//void tree::showResult()
//{
//	while (pCurrent)
//	{
//		BeginBatchDraw();//����������ڿ�ʼ������ͼ��ִ�к��κλ�ͼ����������ʱ���������ͼ�����ϣ�ֱ��ִ�� FlushBatchDraw �� EndBatchDraw �Ž�֮ǰ�Ļ�ͼ�����
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
//	cout << typeName << "�㷨��õ����·���ǣ�" << endl;
//	for (auto it = result.begin(); it != result.end(); it++)
//	{
//		cout << "(" << (*it)->pos.row << ", " << (*it)->pos.col << ")";
//		if (!isEndPoint(*it))//�����յ�ʹ�ӡ��ͷ
//		{
//			cout << " -> ";
//		}
//	}
//	cout << endl;
//
//	cout << "��·�������ǣ�" << costFinal << endl;
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