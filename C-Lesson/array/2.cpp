// 随机产生N个（N由用户定义）0~9之内的整数，分别统计数字0和9出现的次数。
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int n, sum1, sum2;
    int a[n];
    printf("Please input N: ");
    scanf("%d", &n);

    // 乱数种子
    srand((unsigned) time(NULL));
    // 产生[low， up]之间的随机整数
    //（int)((rand() / (RAND_MAX+1.0)) * (up - low + 1.0) + low);

    for (int i = 0; i < n; ++i) {
        a[i] = (int)((rand() / (RAND_MAX + 1.0)) * 10.0);
        if (a[i] == 0) {
            sum1++;
        } else if (a[i] == 9) {
            sum2++;
        }
    }
    printf("The number 0: %d, the number 9: %d", sum1, sum2);

}
