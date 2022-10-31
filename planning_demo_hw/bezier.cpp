//#include"bezier.h"
//
//BezierTest::BezierTest()
//{
//	p0 = { 100.0, 500.0 };
//	p1 = { 300.0, 100.0 };
//	p2 = { 500.0, 100.0 };
//	p3 = { 700.0, 500.0 };
//	p4 = { 900.0, 300.0 };
//
//input:
//	cout << "�����뱴�������߽�����" << endl;
//	cin >> n;
//
//	while (true)
//	{
//		if (n < 0 || n >4)
//		{
//			cout << "����������������һ�Σ�" << endl;
//			goto input;
//		}
//
//		pInit.push_back(p0);
//		if (n == 0)
//		{
//			cout << "0������ֻ��һ�����Ƶ�" << endl;
//			break;
//		}
//		pInit.push_back(p1);
//		if (n == 1)
//		{
//			cout << "1���������������Ƶ�" << endl;
//			break;
//		}
//		pInit.push_back(p2);
//		if (n == 2)
//		{
//			cout << "2���������������Ƶ�" << endl;
//			break;
//		}
//		pInit.push_back(p3);
//		if (n == 3)
//		{
//			cout << "3���������ĸ����Ƶ�" << endl;
//			break;
//		}
//		pInit.push_back(p4);
//		if (n == 4)
//		{
//			cout << "4��������������Ƶ�" << endl;
//			break;
//		}
//	}
//	for (auto it = pInit.begin(); it != pInit.end(); it++)
//	{
//		p.push_back(*it);
//	}
//}
//
//BezierTest::~BezierTest()
//{
//	p.clear();
//}
//
//void BezierTest::showBezierTest(double t)
//{
//	int i = 0;
//	int num = p.size();//���Ƶ���
//
//	while (true)
//	{
//		if (p.size() == 1)
//		{
//			setfillcolor(BLACK);
//			solidcircle(p[0].x, p[0].y, 5);
//			break;
//		}
//
//		double xtmp = (1 - t) * p[i].x + t * p[i + 1].x;
//		double ytmp = (1 - t) * p[i].y + t * p[i + 1].y;
//		Point ptmp;
//		ptmp.x = xtmp;
//		ptmp.y = ytmp;
//
//		if (i > 0)
//		{
//			setlinecolor(RED);
//			double xtmp1 = (1 - t) * p[i - 1].x + t * p[i].x;//��һ����
//			double ytmp1 = (1 - t) * p[i - 1].y + t * p[i].y;
//			line(xtmp, ytmp, xtmp1, ytmp1);
//		}
//
//		setfillcolor(BLUE);
//		solidcircle(xtmp, ytmp, 3);
//
//		p.push_back(ptmp);
//		i++;
//
//		if (i + 1 >= num)//��һ�׼�����ɣ�������һ�׵ļ���
//		{
//			for (int k = 0; k < num; k++)
//			{
//				p.pop_front();
//			}
//			showBezierTest(t);
//		}
//		delay(deltaTime / 5);
//	}
//}
//
//
//void BezierTest::creatBezierTest()
//{
//	for (double t = 0.0; t <= 1.0; t+=delta_time)
//	{
//		showBezierTest(t);
//		p.clear();
//		for (auto it = pInit.begin(); it != pInit.end(); it++)
//		{
//			p.push_back(*it);
//		}
//	}
//}
//
//void BezierTest::delay(int time)
//{
//	clock_t now = clock();
//	while (clock() - now < time)
//	{
//
//	}
//}
//
//
//int main()
//{
//	initgraph(Slength, Swidth, EW_SHOWCONSOLE);
//	setbkcolor(WHITE);
//	cleardevice();
//
//
//	BezierTest test;
//	test.creatBezierTest();
//
//	system("pause");
//	closegraph();
//}