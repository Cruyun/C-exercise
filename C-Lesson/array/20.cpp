//20．(15分)通过循环按行顺序为一个5×5的二维数组a赋1到25的自然数，然后输出该数组的左下半三角。试编程。

#include <stdio.h>

int main()
{
    int a[5][5],i,j,k=0;
    for(i=0;i<5;i++) {
        for (j = 0; j < 5; j++)
            a[i][j] = ++k;
    }
        for (i = 0; i < 5; i++) {
            for (j = 0; j <= i; j++) {
                printf("%2d ", a[i][j]);
            }
            printf("\n");
        }
    return 0;
}
