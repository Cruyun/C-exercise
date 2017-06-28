// 实验四.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const double PI=3.14;
class Rectangle
{
private:
	int X;
	int Y;
	int W;
	int H;
	char *word;
public:
	Rectangle(int x, int y=0, int w=0, int h=0, char *str=NULL)
	{
		X=x, Y=y, W=w, H=h;
		if (str!= NULL)
		{
		word = new char[strlen(str)+1];
		strcpy(word,str);
		}
		else
			word = NULL;
	}
	Rectangle(Rectangle & p)
	{
		X = p.X;
		Y = p.Y;
		H = p.H;
		W = p.W;
     	if (p.word!= NULL)
		{
		word = new char[strlen(p.word)+1];
		strcpy(word,p.word);
		}
		else
			word = NULL;
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
	void set()
	{
		//X=x, Y=y, W=w, H=h;
		char str[100];
		cout<<"输入字符串"<<endl;
		cin>>str;
		word = new char[strlen(str)+1];
		strcpy(word,str);
		cout<<"输入基本信息"<<endl;
		cin>>X>>Y>>W>>H;
	}

	void showRec()
	{
		cout<<"x1="<<X<<" y1="<<Y<<" width="<<W<<" height="<<H<<" "<<word<<endl;
	}
	friend class CPPage;
};

class Circle
{
private:
	double radius;
	int X;
	int Y;
public:
	Circle(double R=0, int x=0, int y=0)
	{
		radius=R;
		X=x;
		Y=y;
	}
	double area()
	{
		return PI*radius*radius;
	}
	~Circle()
	{
		cout << "destructor circle"<<endl;
	}
	void showCircle()
	{
		cout << "the point is ("<<X<<","<<Y<<"), the radius is "<<radius<<endl;
	}
};

class CPPage
{
private:
	int rect_num;
	Rectangle * rect;
	static int count;
public:
	CPPage(int num)
	{
	    rect_num=num;
		rect = new Rectangle[rect_num];
		for (int i=0; i < rect_num;i++)
		{
			rect[i].set();
			rect[i].showRec();
			count++;
		}
	}
	~CPPage()
	{
	   for (int i=0;i<rect_num;i++)
		{
		    delete []rect;
			rect=NULL;
		}
	}
	void show()
	{
	    cout<<"矩形个数"<<count<<endl;
		for (int i=0; i < rect_num;i++)
		{
	       cout<< rect[i].word<<endl;
		}
	}

};
int CPPage::count=0;

int main()
{
	char s[]="ABCED";
	Rectangle rec1[3]={Rectangle(0,0,2,2,s),Rectangle(0,0,2,2,"one"),Rectangle(0,0,2,2,"1234")};
	for(int i=0;i<3;i++)
	    rec1[i].showRec();

	Circle cir1[3]={Circle(5,0,3),Circle(3,1,5),Circle(2,1,3)};
    for(i=0;i<3;i++)
     	cir1[i].showCircle();

	cout<<"-------------"<<endl;

	CPPage cpage(2);
	cpage.show();
	return 0;
}

