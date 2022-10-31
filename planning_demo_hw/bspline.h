#pragma once
#include<iostream>
#include<graphics.h>
#include<vector>
#include<cmath>
#include<ctime>

using namespace std;

constexpr auto Slength = 1200;
constexpr auto Swidth = 1000;
constexpr auto deltaTime = 50;

enum Type {
	uniform,//均匀
	quniform //准均匀
};

class Point {
public:
	double x;
	double y;
};

class Bspline {

public:
	Bspline(int _k,int _type,vector<Point>_p,bool _bDelayShow);
	~Bspline();
	double BsplineBfunc(int i, int k, double uu);//求解B样条基函数
	void creatBspline();
	void delay(int time);//延时函数
public:
	int k;//阶数
	int n;//控制点 - 1
	int type;//b样条类型
	vector<Point>p;//控制点
	vector<Point>pTrack;//轨迹点
	vector<double>u;//自变量
	double uBegin;
	double uEnd;
	double delta_u = 0.01;//间隔
	bool bDelayShow = true;//是否显示曲线生成的过程
};


class BsplineTest {
public:
	void setPoint(vector<Point>& p);//设置控制点
	void MyBsplineTest();
};