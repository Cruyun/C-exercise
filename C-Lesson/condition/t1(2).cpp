#include<stdio.h>
//�������ſεĳɼ���������ųɼ�����60�����ϡ��������it is pass.��ֻҪ��һ�ŵ���60�־������it is not pass.�����������κ�һ�ųɼ�����0-100��Χ���������it is error.����
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
