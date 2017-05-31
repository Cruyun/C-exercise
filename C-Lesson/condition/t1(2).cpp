#include<stdio.h>
//输入两门课的成绩，如果两门成绩都在60分以上。则输出“it is pass.”只要有一门低于60分就输出“it is not pass.”如果输入的任何一门成绩不在0-100范围内则输出“it is error.”。
main(void)
{
    int a,b;
    printf("please input two scores:");
    scanf("%d%d",&a,&b);
    if( (a<0||a>100) || (b<0||b>100))
        printf("it is error.\n");
    else
    {
    a=a/10;
    b=b/10;
    switch(a)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5: switch(b)
            {
             case 0:
             case 1:
             case 2:
             case 3:
             case 4:
             case 5:
             case 6:
             case 7:
             case 8:
             case 9:
             case 10:printf("it is not pass,\n");break;
            }
    case 6:
    case 7:
    case 8:
    case 9:
    case 10: switch(b)
             {
              case 0:
              case 1:
              case 2:
              case 3:
              case 4:
              case 5: printf("it is not pass.\n");break;
              case 6:
              case 7:
              case 8:
              case 9:
              case 10:printf("it is pass.\n");break;
             }
    }
    }
}
