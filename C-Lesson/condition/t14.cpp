#include <stdio.h>
//编程实现以下功能：读入两个运算数（data1和data2）及一个运算符（op），计算表达式data1 op data2的值，其中op可为+，—，*，/（用switch语句实现）。
int main()
{
   char op;
   double data1,data2,r;
   printf("输入两个运算数和一个运算符\n");
   scanf("%lf %c %lf",&data1,&op,&data2);
   switch(op)
   {
      case '+':r=data1+data2;break;
      case '-':r=data1-data2;break;
      case '*':r=data1*data2;break;
      case '/':r=data1/data2;break;
   }
   printf("%.0lf%c%.0lf=%.2lf\n",data1,op,data2,r);
}
