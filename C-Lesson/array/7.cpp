// 计算一个3×3矩阵的主对角线的元素之和sum.
#include <stdio.h>

int main()
{
    int a[3][3];
    int sum;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
            sum += a[i][i];
        }
    }
    printf("%d", sum);
}
