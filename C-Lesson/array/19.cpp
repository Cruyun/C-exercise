//19．(20分)下面是一个5×5阶的螺旋方阵。试编程打印出此形式的n×n（n<10）阶的方阵（顺时针方向旋进）。
//1	2	3	4	5
//16	17	18	19	6
//15	24	25	20	7
//14	23	22	21	8
//13	12	11	10	9

#include <stdio.h>

int main()
{
    int a[10][10];
    int i, j;
    int k = 0;
    int m, n;

    printf("Enter n (n<10):\n");
    scanf("%d",&n);
    if (n % 2 == 0)
        m = n / 2;
    else
        m = n / 2 + 1;
    for (i=0; i<m; i++) {
        for (j=i; j<n-i; j++) {
            k++;
            a[i][j] = k;
        }
        for (j=i+1; j<n-i; j++) {
            k++;
            a[j][n-i-1] = k;
        }
        for (j=n-i-2; j>=i; j--) {
            k++;
            a[n-i-1][j] = k;
        }
        for(j=n-i-2; j>=i+1; j--) {
            k++;
            a[j][i] = k;
        }
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
    return 0;
}
