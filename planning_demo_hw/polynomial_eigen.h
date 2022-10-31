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


class Point //��
{
public:
	double x;
	double y;
};

class CarBase //��������
{
public:
	virtual void showCar(Point p) = 0;
public:
	double length; //���ĳ�
	double width; //���Ŀ�

	Point p0; //���
	Point p1; //�յ�
};

class Car : public CarBase //��
{
public:
	Car(double Rw);
	void showCar(Point p);//������ǳ������ĵ�
};

class CarObs : public CarBase //�ϰ���
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
	double RWidth = 100.0;//·��
	CarBase* car = new Car(RWidth);//��̬������ָ��ָ���������
	CarBase* carObs = new CarObs(RWidth);//��̬������ָ��ָ���������
};

class Mat
{
public:
	//��������T
	void creatMatT(double t0, double t1);
	void eigen_creatMat(double t0, double t1);

	//��������
	void creatVector(double tmp1, double tmp2, double tmp3, double tmp4, double tmp5, double tmp6);
	void eigen_creatVector(double tmp1, double tmp2, double tmp3, double tmp4, double tmp5, double tmp6);

	//��ӡ����
	void PrintMat();

	//�����a��b���������
	void augMat(Mat a, Mat b);
	//������Է�����Ľ�s
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

	//��Ҫ�õ���ϵ��
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

	double disS = road.car->length * 4;//���򻻵�����
	double safeDis = 400;//���򻻵���ȫ����
	double speed = 5.0;
	double delta_time = 0.02;
	int disAhead = safeDis / 50;//ֱ�й滮�ߵļ��
	int State = state1;//����״̬
	vector<Point>trackPoints;
};