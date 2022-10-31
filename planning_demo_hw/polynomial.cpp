//#include"polynomial.h"
//
//Car::Car(double Rw)
//{
//	length = 100.0;
//	width = 60.0;
//
//	p0.x = Swidth / 2 + Rw / 2;
//	p0.y = Sheight  - length;
//
//	p1 = p0;
//
//	cout << "car location: " << p0.x << ", " << p0.y << endl;
//	cout << "car target: " << p1.x << ", " << p1.y << endl;
//}
//
//CarObs::CarObs(double Rw)
//{
//	length = 100.0;
//	width = 60.0;
//
//	p0.x = Swidth / 2 + Rw / 2;
//	p0.y = Sheight / 2 - 4 * length;
//
//	p1 = p0;
//
//	cout << "carobs location: " << p0.x << ", " << p0.y << endl;
//}
//
//void Car::showCar(Point p)
//{
//	setlinestyle(PS_SOLID, 3);
//	setlinecolor(BLACK);
//
//	double leftPos = p.x - width / 2;
//	double rightPos = p.x + width / 2;
//	double topPos = p.y - length / 2;
//	double bottomPos = p.y + length / 2;
//
//	rectangle(leftPos, topPos, rightPos, bottomPos);
//}
//
//void CarObs::showCar(Point p)
//{
//	setlinestyle(PS_SOLID, 3);
//	setlinecolor(RED);
//
//	double leftPos = p.x - width / 2;
//	double rightPos = p.x + width / 2;
//	double topPos = p.y - length / 2;
//	double bottomPos = p.y + length / 2;
//
//	rectangle(leftPos, topPos, rightPos, bottomPos);
//}
//
//Road::Road()
//{
//	showRoad(car->p0);
//}
//
//Road::~Road()
//{
//	if (car != nullptr)
//	{
//		delete car;
//		car = nullptr;
//	}
//	if (carObs != nullptr)
//	{
//		delete carObs;
//		carObs = nullptr;
//	}
//}
//
////绘制道路
//void Road::showRoad(Point p)
//{
//	setlinecolor(BLACK);
//
//	//绘制车道中心线
//	setlinestyle(PS_DASH, 3);
//	line(Swidth / 2, 0, Swidth / 2, Sheight);
//
//	//绘制左右边界
//	setlinestyle(PS_SOLID, 3);
//	line(Swidth / 2 - RWidth, 0, Swidth / 2 - RWidth, Sheight);
//	line(Swidth / 2 + RWidth, 0, Swidth / 2 + RWidth, Sheight);
//
//	car->showCar(p);
//	carObs->showCar(carObs->p0);
//}
//
//void Mat::creatMatT(double t0, double t1)
//{
//	m = n = 6;
//	//构造前三行函数，分别是位置、速度、加速度信息
//	for (int j = 1; j <= n; ++j)
//	{
//		mat[1][j] = pow(t0, n - j);
//		mat[2][j] = (n - j) * pow(t0, n - j - 1);
//		mat[3][j] = (n - j) * (n - j - 1) * pow(t0, n - j - 2);
//
//		if (n - j - 1 < 0)
//		{
//			mat[2][j] = 0.0;
//		}
//
//		if (n - j - 2 < 0)
//		{
//			mat[3][j] = 0.0;
//		}
//	}
//	for (int j = 1; j <= n; ++j)
//	{
//		mat[4][j] = pow(t1, n - j);
//		mat[5][j] = (n - j) * pow(t1, n - j - 1);
//		mat[6][j] = (n - j) * (n - j - 1) * pow(t1, n - j - 2);
//
//		if (n - j - 1 < 0)
//		{
//			mat[5][j] = 0.0;
//		}
//
//		if (n - j - 2 < 0)
//		{
//			mat[6][j] = 0.0;
//		}
//	}
//}
//
//void Mat::creatVector(double tmp1, double tmp2, double tmp3, double tmp4, double tmp5, double tmp6)
//{
//	m = 6;
//	n = 1;
//	
//	mat[1][1] = tmp1;
//	mat[2][1] = tmp2;
//	mat[3][1] = tmp3;
//	mat[4][1] = tmp4;
//	mat[5][1] = tmp5;
//	mat[6][1] = tmp6;
//
//}
//
//void Mat::PrintMat()
//{
//	for (int i = 1; i <= m; ++i)
//	{
//		for (int j = 1; j <= n; ++j)
//		{
//			cout << mat[i][j] << "\t";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//void Mat::augMat(Mat a, Mat b)
//{
//	m = a.m;
//	n = a.n + 1;
//	for (int i = 1; i <= a.m; ++i)
//	{
//		for (int j = 1; j <= a.n; ++j)
//		{
//			mat[i][j] = a.mat[i][j];
//		}
//		mat[i][n] = b.mat[i][1];
//	}
//}
//
//bool Mat::solve(Mat a, Mat b)
//{
//	if (a.n != a.m)
//	{
//		cout << "不为方阵" << endl;
//		return false;
//	}
//
//	//mat的行和列
//	m = a.m;
//	n = 1;
//
//	Mat aa;
//	aa.augMat(a, b);
//	cout << "增广矩阵是" << endl;
//	aa.PrintMat();
//
//	for (int i = 1; i <= aa.m; i++)//因为我们要进行行变换的是方阵，这里的i可以在不同时候需要理解为行或者了列
//	{
//		//寻找第 i 列不为零的元素
//		int k;
//		for (k = i; k <= aa.m; k++)
//		{
//			if (fabs(aa.mat[k][i]) > 1e-10)
//			{
//				break;
//			}
//		}
//
//		//交换第i行和第k行，第k行是mat[k][k]不为0的行
//		if (k <= aa.m)
//		{
//			for (int j = i; j <= aa.n; j++)
//			{
//				aa.mat[0][j] = aa.mat[i][j];
//				aa.mat[i][j] = aa.mat[k][j];
//				aa.mat[k][j] = aa.mat[0][j];
//			}
//
//			//自上向下消除系数
//			double c;
//			//遍历当前i行的下一行，将第i行的
//			for (int j = i + 1; j <= aa.m; j++)
//			{
//				c = -aa.mat[j][i] / aa.mat[i][i];
//				//遍历每一列
//				for (k = i; k <= aa.n; k++)
//				{
//					aa.mat[j][k] += c * aa.mat[i][k];
//				}
//			}
//		}
//		else //没有找到则说明系数矩阵秩不为 n ，说明方程组中有效方程的个数小于 n
//		{
//			cout << "系数矩阵奇异，线性方程组无解或有无数解" << endl;
//			return false;
//		}
//	}
//
//	//自下而上求解
//	for (int i = a.m; i >= 1; i--)
//	{
//		mat[i][1] = aa.mat[i][aa.n];
//		for (int j = a.m; j > i; j--)
//		{
//			mat[i][1] -= mat[j][1] * aa.mat[i][j];
//		}
//		mat[i][1] /= aa.mat[i][i];
//	}
//	return true;
//}
//
////----------------Eigen--------------------//
////Eigen创建矩阵T
//void Mat::eigen_creatMat(double t0, double t1)
//{
//	n = m = 6;
//	for (int j = 0; j < n; ++j)
//	{
//		e_matT(0, j) = pow(t0, n - j - 1);
//		e_matT(1, j) = (n - j) * pow(t0, n - j - 2);
//		e_matT(2, j) = (n - j) * (n - j - 1) * pow(t0, n - j - 3);
//
//		if (n - j - 2 < 0)
//		{
//			e_matT(1, j) = 0.0;
//		}
//
//		if (n - j - 3 < 0)
//		{
//			e_matT(2, j) = 0.0;
//		}
//	}
//
//	for (int j = 0; j < n; ++j)
//	{
//		e_matT(3, j) = pow(t1, n - j - 1);
//		e_matT(4, j) = (n - j - 1) * pow(t1, n - j - 2);
//		e_matT(5, j) = (n - j - 1) * (n - j - 2) * pow(t1, n - j - 3);
//
//		if (n - j - 2 < 0)
//		{
//			e_matT(4, j) = 0.0;
//		}
//
//		if (n - j - 3 < 0)
//		{
//			e_matT(5, j) = 0.0;
//		}
//	}
//}
//
//void Mat::eigen_creatVector(double tmp1, double tmp2, double tmp3, double tmp4, double tmp5, double tmp6)
//{
//	e_vector(0, 1) = tmp1;
//	e_vector(1, 1) = tmp2;
//	e_vector(2, 1) = tmp3;
//	e_vector(3, 1) = tmp4;
//	e_vector(4, 1) = tmp5;
//	e_vector(5, 1) = tmp6;
//
//}
//
//bool Mat::eigen_solve(Eigen::Matrix<double, 6, 6> m1, Eigen::Matrix<double, 6, 1>m2)
//{
//
//	//直接求逆
//	e_solve = m1.inverse() * m2;
//	////QR分解
//	//e_solve = m1.colPivHouseholderQr().solve(m2);
//	////cholesky
//	//e_solve = m1.llt().solve(m2);
//	return true;
//}
//
////----------------Polynomial--------------------//
//Polynomial::Polynomial()
//{
//	showAheadTrack();
//	system("pause");
//}
//
//void Polynomial::ahead()
//{
//	while (true)
//	{
//		BeginBatchDraw();
//		cleardevice();
//		setlinecolor(BLACK);
//
//		road.car->p0.y -= speed;
//		road.car->p1.y -= speed;
//		road.showRoad(road.car->p0);
//		showAheadTrack();
//
//		EndBatchDraw();
//
//		if (road.car->p0.y - road.carObs->p0.y <= safeDis && State == state1
//			|| road.car->p0.y <= -50.0 && State == state2)
//		{
//			break;
//		}
//		delay(deltaTime);
//	}
//}
//
//void Polynomial::showAheadTrack()
//{
//	setfillcolor(BLUE);
//	Point pt = road.car->p0;
//	for (int i = 0; i < 50; ++i)
//	{
//		pt.y -= disAhead;
//		solidcircle(pt.x, pt.y, 3);//画点
//	}
//}
//
//
////根据参数构造五次多项式，然后计算出A B中的值
//void Polynomial::calMat()
//{
//	//初始化系数
//	x0 = road.car->p0.x;
//	y0 = road.car->p0.y;
//
//	road.car->p1.x = Swidth / 2 - road.RWidth / 2;
//	road.car->p1.y = road.car->p0.y - disS;
//
//	x1 = road.car->p1.x;
//	y1 = road.car->p1.y;
//	cout << x0 << ", " << y0 << ", " << x1 << ", " << y1 << endl;
//
//	X.creatVector(x0, vx0, ax0, x1, vx1, ax1);
//	Y.creatVector(y0, vy0, ay0, y1, vy1, ay1);
//	T.creatMatT(t0, t1);
//	cout << endl;
//	cout << "X向量：" << endl;
//	X.PrintMat();
//	cout << "Y向量：" << endl;
//	Y.PrintMat();
//	cout << "T矩阵：" << endl;
//	T.PrintMat();
//
//	if (A.solve(T, X))
//	{
//		cout << "求得的A向量如下" << endl;
//		A.PrintMat();
//	}
//
//	if (B.solve(T, Y))
//	{
//		cout << "求得的B向量如下" << endl;
//		B.PrintMat();
//	}
//}
//
//void Polynomial::showTrack()
//{
//	calMat();
//	//已知A、B，将轨迹用数学的方式表达出来，并且进行离散化处理
//	setlinecolor(BLUE);
//	for (double t = t0; t < t1; t += delta_time)
//	{
//		double x_temp = A.mat[1][1] * pow(t, 5) + A.mat[2][1] * pow(t, 4) + A.mat[3][1] * pow(t, 3) + A.mat[4][1] * pow(t, 2) + A.mat[5][1] * pow(t, 1) + A.mat[6][1];
//		double y_temp = B.mat[1][1] * pow(t, 5) + B.mat[2][1] * pow(t, 4) + B.mat[3][1] * pow(t, 3) + B.mat[4][1] * pow(t, 2) + B.mat[5][1] * pow(t, 1) + B.mat[6][1];
//
//		solidcircle(x_temp, y_temp, 3);
//
//		Point temp;
//		temp.x = x_temp;
//		temp.y = y_temp;
//
//		trackPoints.push_back(temp);
//	}
//}
//
////车辆换道
//void Polynomial::carMove()
//{
//	showTrack();
//
//	for (auto it = trackPoints.begin(); it != trackPoints.end(); it++)
//	{
//		BeginBatchDraw();
//		cleardevice();
//		setfillcolor(BLUE);
//
//		for (auto ii = it; ii != trackPoints.end(); ii++)
//		{
//			solidcircle(ii->x, ii->y, 3);
//		}
//		road.showRoad(*it);
//		road.car->p0.x = it->x;
//		road.car->p0.y = it->y;
//
//		EndBatchDraw();
//		//delay(deltaTime);
//	}
//
//	State = state2;
//}
//void Polynomial::process()
//{
//	ahead();
//	carMove();
//	ahead();
//}
//
//void Polynomial::showResult()
//{
//	initgraph(Swidth * 2, Sheight / 2, EW_SHOWCONSOLE);
//	setbkcolor(WHITE);
//	setfillcolor(RED);
//	setlinecolor(BLACK);
//	setlinestyle(PS_SOLID, 3);
//	cleardevice();
//	setorigin(Swidth, Sheight / 4);
//
//	line(-Swidth, 0, Swidth, 0);//x轴
//	line(0, Sheight, 0, -Sheight);//y轴
//
//	//时间t与速度v的关系
//	for (double t = t0; t <= t1; t += delta_time)
//	{
//		double vx_tmp = 5 * A.mat[1][1] * pow(t, 4) + 4 * A.mat[2][1] * pow(t, 3) + 3 * A.mat[3][1] * pow(t, 2) + 2 * A.mat[4][1] * pow(t, 1) + A.mat[5][1];
//		double vy_tmp = 5 * B.mat[1][1] * pow(t, 4) + 4 * B.mat[2][1] * pow(t, 3) + 3 * B.mat[3][1] * pow(t, 2) + 2 * B.mat[4][1] * pow(t, 1) + B.mat[5][1];
//		
//		solidcircle(t * 150, vx_tmp, 3);
//		solidcircle(t * 150, vy_tmp, 3);
//	}
//	system("pause");
//	cleardevice();
//
//	line(-Swidth, 0, Swidth, 0);//x轴
//	line(0, Sheight, 0, -Sheight);//y轴
//
//	//时间t与加速度a的关系
//	for (double t = t0; t <= t1; t += delta_time)
//	{
//		double ax_tmp = 20 * A.mat[1][1] * pow(t, 3) + 12 * A.mat[2][1] * pow(t, 2) + 6 * A.mat[3][1] * pow(t, 1) + 2 * A.mat[4][1];
//		double ay_tmp = 20 * B.mat[1][1] * pow(t, 3) + 12 * B.mat[2][1] * pow(t, 2) + 6 * B.mat[3][1] * pow(t, 1) + 2 * B.mat[4][1];
//
//		solidcircle(t * 150, ax_tmp * 2, 3);
//		solidcircle(t * 150, ay_tmp * 2, 3);
//	}
//}
//
//void Polynomial::delay(int time)
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
//	initgraph(Swidth, Sheight, EW_SHOWCONSOLE);
//	setbkcolor(WHITE);
//	cleardevice();
//
//	Polynomial p;
//	p.process();
//
//	system("pause");
//	closegraph();
//
//	p.showResult();
//
//	system("pause");
//	closegraph();
//
//	return 0;
//}