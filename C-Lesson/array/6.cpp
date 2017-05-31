// 打印出杨辉三角形(要求打印出前五行).
#include <stdio.h>
#define N 14

void main()
{
    int i, j, k, a[N][N];  /*定义二维数组a[14][14]*/

    for (i = 0; i < 5; i++) {
        a[i][1] = a[i][i] = 1;
    }
    for (i = 2; i < 5; i++) {
        for (j = 2; j < i; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    for(i = 0; i < n; i++) {
        for (k = 0; k < n - i; k++) {
            printf("   ");
        }
        for (j = 0; j < i; j++) {
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
