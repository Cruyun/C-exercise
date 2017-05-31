/*
  显示读取整数的最后一位数字
*/

#include <stdio.h>

int main(void)
{
    int no;

    printf("请输入一个整数:");
    scanf("%d", &no);          /*读取整数的值*/

    printf("最后一位是%d。 /n",no % 10); /*no除以10所得的余数*/

    return 0;
}
