// 程序读入20个整数，统计并输出非负数个数以及非负数的和。
#include <stdio.h>

int main()
{
    int a[20];
    int n, sum;
    for (int i = 0; i < 20; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= 0) {
            n++;
            sum += a[i];
        }
    }
    printf("%d, %d", n, sum);
}
