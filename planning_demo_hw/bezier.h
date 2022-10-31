#pragma once
#include<iostream>
#include<graphics.h>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>

using namespace std;

constexpr auto Swidth = 600;
constexpr auto Slength = 1200;
constexpr auto deltaTime = 50;

class Point {
public:
	double x;
	double y;
};

class BezierTest
{
public:
	BezierTest();
	~BezierTest();
	void showBezierTest(double t);
	void creatBezierTest();
	void delay(int time);

public:
	Point p0, p1, p2, p3, p4;
	int n;
	vector<Point>pInit;
	deque<Point>p;//Ë«¶Ë¶ÓÁÐ
	double delta_time = 0.02;

};