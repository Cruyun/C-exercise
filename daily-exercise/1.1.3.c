/*
   读取一个整数并显示该证书加上12之后的结果
*/

#include <stdio.h>

int main(void)
{
    int no;

    printf("输入一个整数:");
    scanf("%d", &no);

    printf("该数加上12的结果是：%d。\n", no + 12);

    return 0;
}
