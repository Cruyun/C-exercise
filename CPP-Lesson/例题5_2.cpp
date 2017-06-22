// 例题5_2.cpp : Defines the entry point for the console application.
//
/* 构造函数与析构函数*/

#include "stdafx.h"
#include <iostream>
using namespace std;

class Clock {
private:
	int H,M,S;
public:
	Clock(int h=0,int m=0, int s=0)
	{
		H=h,M=m,S=s;
		cout<< "constructor:" <<H<<":"<<M<<":"<<":"<<S<<endl;
	}
	~Clock() 
	{
		cout<<"destructor"<<H<<":"<<M<<":"<<":"<<S<<endl;
	}
};

int main( )
{
	Clock C3(10,0,0);
	Clock c4(11,0,0);
	return 0;
}
Clock c1(8,0,0);
Clock c2(9,0,0);
