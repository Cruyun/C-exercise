// 求出某数组a[5][5]每行元素的平均值。
#include <stdio.h>

int main()
{
    int a[5][5];
    int sum, ave;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", a[i][j]);
            sum += a[i][j];
            ave = sum / 5;
            printf("%d\n", ave);
        }
    }
}