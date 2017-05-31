 /*
    读取一个整数并显示其五倍数的值
*/

#include <stdio.h>

int main(void)
{
    int no;

    printf("请输入一个整数：");
    scanf("%d", &no);

    printf("他的五倍数是%d。\n", 5 * no);

    return 0;
}
