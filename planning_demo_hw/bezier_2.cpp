//#include<iostream>
//#include<graphics.h>
//#include<conio.h>
//#include<vector>
//#include<windows.h>
//using namespace std;
//
//void GetBezier(const int* xArray, const int* yArray, const unsigned& n)
//{
//	initgraph(1000, 700);
//	for (int i = 0; i < n - 1; i++)
//	{
//		fillcircle(xArray[i], yArray[i], 3);
//		line(xArray[i], yArray[i], xArray[i + 1], yArray[i + 1]);
//	}
//	fillcircle(xArray[n - 1], yArray[n - 1], 3);
//	_getch();
//	for (float t = 0; t <= 1; t += 0.001)
//	{
//		vector<double>xvec, yvec;
//		for (unsigned i = 0; i < n; i++)
//		{
//			xvec.push_back(xArray[i]);
//			yvec.push_back(yArray[i]);
//		}
//		for (unsigned Current_PointNum = n; Current_PointNum > 1; Current_PointNum--)
//		{
//			for (unsigned i = 0; i < Current_PointNum - 1; i++)
//			{
//				xvec[i] = (1 - t) * xvec[i] + t * xvec[i + 1];
//				yvec[i] = (1 - t) * yvec[i] + t * yvec[i + 1];
//			}
//		}
//		putpixel(xvec[0], yvec[0], GREEN);
//		Sleep(1);
//	}
//	_getch();
//	closegraph();
//	return;
//}
//
//int main(void)
//{
//	unsigned pointNum;
//	cout << "请输入控制多边形点的个数：";
//	cin >> pointNum;
//	int* xArray = new int[pointNum];
//	int* yArray = new int[pointNum];
//	cout << "请分别输入各个点的横纵坐标值：" << endl;
//	for (int i = 0; i < pointNum; i++)
//	{
//		cin >> xArray[i] >> yArray[i];
//	}
//	cout << "参数确认完毕，按任意键开始绘图..." << endl;
//	_getch();
//	GetBezier(xArray, yArray, pointNum);
//	return 0;
//}
//
