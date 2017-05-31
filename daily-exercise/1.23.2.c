/*
  读取两个整数，显示他们的伤和玉树
  */

#include <stdio.h>

int main(void)
{
    int a, b;

    puts("请输入两个整数");
    printf("整数a"); scanf("%d", &a);
    printf("整数b"); scanf("%d", &b);

    printf("a除以b得%d余%d。\n", a / b, a & b);

    return 0;
}
