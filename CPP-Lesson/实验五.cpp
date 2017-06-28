// สตั้ฮๅ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CGraph
{
private:
	int x;
	int y;
	int type;
	char * color;
	int linewidth;
public:
	CGraph(int x=0, int y=0,int type=0, char *str =NULL, int linewidth =0)
	{
		this->x=x, this->y=y,this->type=type,  this->linewidth=linewidth;
		if (str!= NULL)
		{
		color = new char[strlen(str)+1];
		strcpy(color,str);
		}
		else
			color = NULL;
	}
	~CGraph()
	{
		cout<<"destructor CGraph"<<endl;
		if(color != NULL)
		{
			delete [] color;
			color = NULL;
		}
	}
	void showInfo()
	{
		cout<<"x:"<<x<<" y:"<<y<<" type:"<<type<<" color: "<<color<<" linewidth: "<<linewidth<<endl;
	}
};

class Rectangle: virtual public CGraph
{
private:
	int W;
	int H;
	char *word;
public:
	Rectangle(int x, int y,int type, char * color,int linewidth,int w, int h, char *str):CGraph(x, y,type, color, linewidth)
	{
	    W=w, H=h;
		if (str!= NULL)
		{
		word = new char[strlen(str)+1];
		strcpy(word,str);
		}
		else
			word = NULL;
	}
	Rectangle():CGraph()
	{
        W=0;
        H=0;
        word = NULL;
    };
	~Rectangle()
	{
		cout<<"destructor rectangle"<<endl;
		if(word != NULL)
		{
			delete [] word;
			word = NULL;
		}
	}
	void show()
	{
		showInfo();
		cout<<"width="<<W<<" height="<<H<<" "<<word<<endl;
	}
	friend class CPPage;
};

class Circle: virtual public CGraph
{
private:
	double radius;
public:
	Circle(int x, int y,int type, char * color,int linewidth,double R):CGraph(x, y,type, color,linewidth)
	{
		radius=R;
	}
	Circle():CGraph()
	{
        radius=0;
    };
	~Circle()
	{
		cout << "destructor circle"<<endl;
	}
	void show()
	{
		showInfo();
		cout <<"the radius is "<<radius<<endl;
	}
};

class CCircleRect: public Rectangle, public Circle
{
public:
	CCircleRect(int Rx,int Ry,int Rtype,char * Rcolor, int Rlinewidth,int Cx, int Cy, int Ctype,char *Ccolor, int Clinewidth, int W, int H, char * word, int radius)
		:CGraph(Rx,Ry,Rtype,Rcolor,Rlinewidth),Rectangle(Rx,Ry,Rtype,Rcolor,Rlinewidth,W,H,word),Circle(Cx,Cy,Ctype,Ccolor,Clinewidth,radius)
	{
		cout<<"constructing ccirclerect"<<endl;
	}
	CCircleRect() : CGraph(), Rectangle(), Circle() {}
	void show()
	{
		cout<<"CCircle:"<<endl;
		Rectangle::show();
		Circle::show();
	}
};

class CPPage
{
private:
	int cp_num;
	CCircleRect CR;
public:
	CPPage(int cp_num, int Rx,int Ry,int Rtype,char * Rcolor, int Rlinewidth,int Cx, int Cy, int Ctype,char *Ccolor, int Clinewidth, int W, int H, char * word, int radius)
		:CR(Rx,Ry,Rtype,Rcolor,Rlinewidth,Cx,Cy,Ctype,Ccolor,Clinewidth,W,H,word,radius)
	{
	   this->cp_num=cp_num;
	}
	~CPPage()
	{
	   cout<<"constructing cppage"<<endl;
	}
	void showCP()
	{
		CR.show();
	}
};

int main()
{
	Rectangle g1(1,1,0,"blue",1,1,1,"haha");
	g1.showInfo();
	Circle c1(2,2,1,"green",2,2);
	c1.showInfo();

	CCircleRect CR1(1,1,0,"blue",2,2,1,1,"green",2,2,2,"haha",1);
	CR1.show();
	
	CPPage CP(1,1,1,0,"blue",2,2,1,1,"green",2,2,2,"haha",1);
	CP.showCP();
	return 0;
}

