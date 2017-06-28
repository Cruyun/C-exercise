// 实验六.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
using namespace std;

class CGraph
{
protected:
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
    virtual ~CGraph()
    {
        cout<<"~CGraph() called"<<endl;
        if(color != NULL)
        {
            delete [] color;
            color = NULL;
        }
    }
    virtual void showMsg()=0;
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
    Rectangle():CGraph(){};
    ~Rectangle()
    {
        cout<<"destructor rectangle"<<endl;
        if(word != NULL)
        {
            delete [] word;
            word = NULL;
        }
    }
    void showMsg()
    {
        cout<<"x:"<<x<<" y:"<<y<<" type:"<<type<<" color: "<<color<<" linewidth: "<<linewidth<<endl;
        cout<<"width="<<W<<" height="<<H<<" "<<"word"<<word<<endl;
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
    Circle():CGraph(){};
    ~Circle()
    {
        cout << "destructor circle"<<endl;
    }
    void showMsg()
    {
        cout<<"x:"<<x<<" y:"<<y<<" type:"<<type<<" color: "<<color<<" linewidth: "<<linewidth<<endl;
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
    CCircleRect():CGraph(),Rectangle(),Circle(){};
    void showMsg()
    {
        cout<<"CCircle:"<<endl;
        Rectangle::showMsg();
        Circle::showMsg();
    }
};


class CPPage
{
private:
    CGraph * graph[100];
    int num;
public:
    CPPage()
    {
        int x, y, w, h, linewidth, radius, rect_num, cir_num, type;
        char color[20] = {0};
        char word[20] = {0};
        cout << "请输入图形个数" << endl;
        cin >>num;
        for (int i = 0; i < num; i++) {
            cout << "请输入图形类型" << endl;
            cin >> type;
            switch (type) {
                case 0:
                    cout << "请输入矩形的信息" << endl;
                        cout << "x:";
                        cin >> x;
                        cout << "y:";
                        cin >> y;
                        cout << "w:";
                        cin >> w;
                        cout << "h:";
                        cin >> h;
                        cout << "linewidth:";
                        cin >> linewidth;
                        cout << "color:";
                        cin >> color;
                        cout << "word:";
                        cin >> word;
                        graph[i] = new Rectangle(x, y, 0, color, linewidth, w, h, word);
                case 1:
                    cout << "请输入圆形的信息" << endl;
                        cout << "x:";
                        cin >> x;
                        cout << "y:";
                        cin >> y;
                        cout << "linewidth:";
                        cin >> linewidth;
                        cout << "color:";
                        cin >> color;
                        cout << "radius:";
                        cin >> radius;
                        graph[i] = new Circle(x, y, 1, color, linewidth, radius);
            }
        }
    }
    void showMsg()
    {
        for(int i=0;i<num;i++)
        {
            graph[i]->showMsg();
            delete graph[i];
        }
    }

        ~CPPage()
        {
            cout<<"~cppage() called"<<endl;
        }
};

int main()
{
    char c[5]="blue",c2[6]="green",*d1,*d2;
    d1=c,d2=c2;
    char w1[5]="haha",*w;
    w=w1;
    Rectangle g1(1,1,0,d1,1,1,1,w);
    g1.showMsg();
    Circle c1(2,2,1,d2,2,2);
    c1.showMsg();
    CCircleRect CR1(1,1,0,d1,2,2,1,1,d2,2,2,2,w,1);
    CR1.showMsg();

    CPPage CP;
    CP.showMsg();
    return 0;
}

