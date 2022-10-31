#include"bspline.h"

Bspline::Bspline(int _k, int _type, vector<Point>_p, bool _bDelayShow)
{
	k = _k;//阶数
	n = _p.size() - 1;//控制点数 - 1
	bDelayShow = _bDelayShow;

	//k<=n+1且控制点n>0
	if (k > n + 1 || _p.empty())
	{
		cout << "error!" << endl;
		system("pause");
		exit(0);
	}

	type = _type;//节点矢量的类型（均匀\非均匀）
	p = _p;//控制点

	//第一个节点u
	double u_tmp = 0.0;
	u.push_back(u_tmp);

	if (type == uniform)
	{
		double dis_u = 1.0 / (k + n);//dis_u是用来划分节点间隔的 总共有k+n+1个 然后分为k+n段
		for (int i = 1; i < n + k + 1; i++)
		{
			u_tmp += dis_u;
			u.push_back(u_tmp);
		}
	}
	else if (type == quniform)
	{
		int j = 3;
		//重复度
		double dis_u = 1.0 / (k + n - (j - 1) * 2);
		for (int i = 1; i < j; i++)
		{
			u.push_back(u_tmp);
		}
		for (int i = j; i < n + k + 1 - (j - 1); i++)
		{
			u_tmp += dis_u;
			u.push_back(u_tmp);
		}
		for (int i = n + k + 1 - (j - 1); i < n + k + 1; i++)
		{
			u.push_back(u_tmp);
		}
	}

	cout << "阶数：" << k << ", 控制点数：" << n + 1 << endl;
	cout << "delta_u= " << delta_u << ", u的序列为：";
	for (int i = 0; i < u.size(); i++)
	{
		cout << u[i] << ", ";
	}
	cout << endl;

	uBegin = u[k - 1];
	uEnd = u[n+1];//计算u的区间
	cout << "uBegin= " << uBegin << ", uEnd= " << uEnd << endl;

	if (bDelayShow)
	{
		//画控制点
		setfillcolor(BLACK);
		for (auto it = p.begin(); it != p.end(); it++)
		{
			solidcircle(it->x, it->y, 3);
		}
		system("pause");
	}
}

Bspline::~Bspline()
{
	p.clear();
	u.clear();
	pTrack.clear();
}

double Bspline::BsplineBfunc(int i, int k, double uu)
{
	double Bfunc = 0.0;
	if (k == 1)
	{
		if (uu >= u[i] && uu < u[i+1])
		{
			Bfunc = 1.0;
		}
		else 
		{
			Bfunc = 0.0;
		}
	}
	else if (k >= 2)
	{
		double A = 0.0;
		double B = 0.0;
		if (u[i + k - 1] - u[i] == 0.0)
		{
			A = 0.0;
		}
		else
		{
			A = (uu - u[i]) / (u[i + k - 1] - u[i]);
		}

		if (u[i + k] - u[i + 1] == 0.0)
		{
			B = 0.0;
		}
		else {
			B = (u[i + k] - uu) / (u[i + k] - u[i + 1]);
		}

		Bfunc = A * BsplineBfunc(i, k - 1, uu) + B * BsplineBfunc(i + 1, k - 1, uu);
	}
	cout << "Bfunc= " << Bfunc << endl;
	return Bfunc;
}

void Bspline::creatBspline()
{
	setfillcolor(RED);
	//定义域的作用
	for (double uu = uBegin; uu <= uEnd; uu += delta_u)
	{
		Point pu = { 0.0,0.0 };
		for (int i = 0; i < n + 1; i++)
		{
			double x_tmp = p[i].x;
			double y_tmp = p[i].y;
			double Bfunctmp = BsplineBfunc(i, k, uu);
			pu.x += x_tmp * Bfunctmp;
			pu.y += y_tmp * Bfunctmp;
		}
		solidcircle(pu.x, pu.y, 4);//B样条轨迹点最终是关于u的函数
		pTrack.push_back(pu);//轨迹点

		delay(50);//显示轨迹点生成过程
	}

	cout << "track point: " << endl;
	for (auto it = pTrack.begin(); it != pTrack.end(); it++)
	{
		cout << "(" << it->x << ", " << it->y << ") ";
	}
	cout << endl;
}

void Bspline::delay(int time)
{
	clock_t now = clock();
	while (clock() - now < 50)
	{

	}
}

void BsplineTest::setPoint(vector<Point>& p)//定义点
{
	p.push_back(Point{ 100.0, 300.0 });
	p.push_back(Point{ 200.0, 100.0 });
	p.push_back(Point{ 300.0, 200.0 });
	p.push_back(Point{ 400.0, 50.0 });
	p.push_back(Point{ 550.0, 100.0 });
	p.push_back(Point{ 600.0, 350.0 });
	p.push_back(Point{ 700.0, 350.0 });
}


void BsplineTest::MyBsplineTest()//任意点测试
{
	vector<Point> pcontrol;
	setPoint(pcontrol);
	 
	Bspline test(3, quniform, pcontrol, true);
	test.creatBspline();
}

int main()
{
	initgraph(Slength, Swidth, EW_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();

	BsplineTest myTest;
	myTest.MyBsplineTest();//任意点测试

	system("pause");
	return 0;
}