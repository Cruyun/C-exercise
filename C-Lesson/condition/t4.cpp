//(12分)编写一个程序，输入一个整数，判断它能不能被 5 或 8 整除，若能，输出“ Can ”，否则输出“ Cannot ”。


#include <stdio.h>

int main()
{
    int a;

    scanf("%d",&a);
    if(a%5==0||a%8==0)
    printf("can");
    else printf("Cannot");
    return 0;
}
