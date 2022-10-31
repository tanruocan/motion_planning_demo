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
	uniform,//����
	quniform //׼����
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
	double BsplineBfunc(int i, int k, double uu);//���B����������
	void creatBspline();
	void delay(int time);//��ʱ����
public:
	int k;//����
	int n;//���Ƶ� - 1
	int type;//b��������
	vector<Point>p;//���Ƶ�
	vector<Point>pTrack;//�켣��
	vector<double>u;//�Ա���
	double uBegin;
	double uEnd;
	double delta_u = 0.01;//���
	bool bDelayShow = true;//�Ƿ���ʾ�������ɵĹ���
};


class BsplineTest {
public:
	void setPoint(vector<Point>& p);//���ÿ��Ƶ�
	void MyBsplineTest();
};