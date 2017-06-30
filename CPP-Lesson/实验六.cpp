// 实验六.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
using namespace std;

static int count3=0;
class CGraph
{
protected:
    int x;
    int y;
    int type;
    char * color;
    int linewidth;
public:
    CGraph(int x=0, int y=0,int type=0, char *str = NULL, int linewidth =0)
    {
        this->x=x,this->y=y,this->type=type,this->linewidth=linewidth;
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
    char * word;
    static int count1;
public:
    Rectangle(int x, int y,int type, char * color,int linewidth, int w, int h, char *str)
            :CGraph(x, y,type, color, linewidth)
    {
        W=w, H=h;
        if (str!= NULL)
        {
            word = new char[strlen(str)+1];
            strcpy(word,str);
        }
        else
            word = NULL;
        count1++;
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
        cout << "------------------------------------------" << endl;
    }

    static void getCount1()
    {
        cout<<"矩形的数量是:"<<count1-count3<<endl;
    }
    friend class CPPage;
};

int Rectangle::count1=0;

class Circle: virtual public CGraph
{
private:
    double radius;
    static int count2;
public:
    Circle(int x, int y,int type, char * color,int linewidth,double R)
            :CGraph(x, y,type, color,linewidth)
    {
        radius=R;
        count2++;
    }
    Circle():CGraph(){
        count2++;
    }
    ~Circle()
    {
    }
    void showMsg()
    {
        cout<<"x:"<<x<<" y:"<<y<<" type:"<<type<<" color: "<<color<<" linewidth: "<<linewidth<<endl;
        cout <<"the radius is "<<radius<<endl;
        cout << "------------------------------------------" << endl;
    }
    static void getCount2()
    {
        cout<<"圆形的数量是:"<<count2-count3<<endl;
    }
};

int Circle::count2=0;

class CCircleRect: public Rectangle, public Circle
{
public:
    CCircleRect(int x,int y,int type,char * color, int linewidth,
                int W, int H, char * word, int radius)
            :CGraph(x,y,type,color,linewidth),
             Rectangle(x,y,type,color,linewidth,W,H,word),
             Circle(x,y,type,color,linewidth,radius)
    {
        count3++;
    }

    CCircleRect():CGraph(),Rectangle(),Circle(){}

    void showMsg()
    {
        cout<<"CCircleRect:"<<endl;
        Rectangle::showMsg();
        Circle::showMsg();
        cout << "------------------------------------------" << endl;
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
        num=0;
    }
    void setInfo()
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
                    break;
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
                    break;
                case 2:
                    cout << "请输入圆角矩形的信息" << endl;
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
                    cout << "radius:";
                    cin >> radius;
                    cout << "word:";
                    cin >> word;
                    graph[i] = new CCircleRect(x,y,2,color,linewidth,w,h,word,radius);
                    break;
                default:
                    cout << "请输入图形信息" << endl;
                    break;
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
        Rectangle::getCount1();
        Circle::getCount2();
        cout<<"圆角矩形的数量是:"<<count3<<endl;
    }

    ~CPPage()
    {
    }
};

int main()
{
    CPPage CP;
    CP.setInfo();
    CP.showMsg();
    return 0;
}

