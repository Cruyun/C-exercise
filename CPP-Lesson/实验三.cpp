// สตั้ศý.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Rectangle
{
private:
	int X;
	int Y;
	int W;
	int H;
	char *word;
public:
	Rectangle(int x=0, int y=0, int w=0, int h=0, char *str=NULL)
	{
		X=x, Y=y, W=w, H=h;
		word = str; 
	}
	Rectangle(Rectangle & p)
	{
		X = p.X;
		Y = p.Y;
		H = p.H;
		W = p.W;
		word = p.word;
	}
	Rectangle()
	{
		X=0, Y=0, W=0, H=0;
		word = NULL;
	}
	~Rectangle()
	{
		cout<<"destructor "<<endl;
		if(word != NULL)
		{
			delete [] word;
			word = NULL;
		}
	}
	void show()
	{
		cout<<"x1="<<X<<" y1="<<Y<<" width="<<W<<" height="<<H<<" "<<word<<endl;
	}
};

int main()
{
	char s[]="ABCED";
	Rectangle rec1(0,0,10,10,s);
	Rectangle rec2(0,0,10,10,"word");
	rec1.show();

	return 0;
}

