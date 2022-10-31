#pragma once
#include<iostream>
#include <cmath>
#include <ctime>
#include<graphics.h>
#include<vector>
#include<Eigen/Dense>
#include <Eigen/Core>

using namespace std;
using namespace Eigen;

constexpr auto N = 10;
constexpr auto Swidth = 600;
constexpr auto Sheight = 1200;
constexpr auto deltaTime = 50;

enum
{
	state1,
	state2
};


class Point //点
{
public:
	double x;
	double y;
};

class CarBase //车：基类
{
public:
	virtual void showCar(Point p) = 0;
public:
	double length; //车的长
	double width; //车的宽

	Point p0; //起点
	Point p1; //终点
};

class Car : public CarBase //车
{
public:
	Car(double Rw);
	void showCar(Point p);//输入的是车的中心点
};

class CarObs : public CarBase //障碍车
{
public:
	CarObs(double Rw);
	void showCar(Point p);
};

class Road
{
public:
	Road();
	~Road();
	void showRoad(Point p);

public:
	double RWidth = 100.0;//路宽
	CarBase* car = new Car(RWidth);//多态：父类指针指向子类对象
	CarBase* carObs = new CarObs(RWidth);//多态：父类指针指向子类对象
};

class Mat
{
public:
	//创建矩阵T
	void creatMatT(double t0, double t1);
	void eigen_creatMat(double t0, double t1);

	//创建向量
	void creatVector(double tmp1, double tmp2, double tmp3, double tmp4, double tmp5, double tmp6);
	void eigen_creatVector(double tmp1, double tmp2, double tmp3, double tmp4, double tmp5, double tmp6);

	//打印矩阵
	void PrintMat();

	//求矩阵a和b的增广矩阵
	void augMat(Mat a, Mat b);
	//求解线性方程组的解s
	bool solve(Mat a, Mat b);
	bool eigen_solve(Eigen::Matrix<double, 6, 6> m1, Eigen::Matrix<double, 6, 1>m2);
public:
	Eigen::Matrix<double, 6, 6> e_matT;
	Eigen::Matrix<double, 6, 1> e_vector;
	Eigen::Matrix<double, 6, 1>e_solve;
	int m;
	int n;
	double mat[N][N] = { 0 };
};

class Polynomial {
public:
	Polynomial();

	void ahead();
	void showAheadTrack();
	void calMat();
	void showTrack();
	void carMove();
	void delay(int time);
	void process();
	void showResult();

public:
	Road road;

	//需要用到的系数
	double t0 = 0.0;
	double t1 = 3.0;
	double x0 = road.car->p0.x;
	double y0 = road.car->p0.y;
	double x1 = road.car->p1.x;
	double y1 = road.car->p1.y;
	double vx0 = 0.0;
	double vy0 = -120.0;
	double vx1 = 0.0;
	double vy1 = -120.0;
	double ax0 = 0.0;
	double ay0 = 0.0;
	double ax1 = 0.0;
	double ay1 = 0.0;

	Mat X;
	Mat Y;
	Mat T;
	Mat A;
	Mat B;
	 
	//Matrix <double, 6, 1>X_e;
	//Matrix <double, 6, 1>Y_e;
	//Matrix <double, 6, 6>T_e;
	//Matrix <double, 6, 1>A_e;
	//Matrix <double, 6, 1>B_e;

	double disS = road.car->length * 4;//纵向换道距离
	double safeDis = 400;//纵向换道安全距离
	double speed = 5.0;
	double delta_time = 0.02;
	int disAhead = safeDis / 50;//直行规划线的间隔
	int State = state1;//车辆状态
	vector<Point>trackPoints;
};