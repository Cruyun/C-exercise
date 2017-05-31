// 写一个函数，将一个整型数x插入到由小到大排列的整型数组a[0]~a[N-1]中，使得插入元素后的数组a[0]~a[N]保持升序。
#include "stdio.h" 
#define N 10  

// 选择排序
void SelSort(int a[N])
{
    int i,j,min,t;
    for (i = 0;i < N-1;i++) {
        for (j = i + 1;j < N;j++)
            if(a[j] < a[i]) {
                t = a[i];
                a[i] = a[min];
                a[min] = t;
            }
    }
}

void main()
{
    int a[N],i;
    for(i = 0;i < N;i++) {
        scanf("%d", a + i);
    }
    SelSort(a);
    for (i = 0;i < N;i++) {
        printf("%6d", a[i]);
    }
}

/* 改进选择排序
void SelSort(int a[N])
{
    int i,j,min,t;
    for (i = 0; i < N-1; i++) {
        min = i;
        for (j = i + 1; j < N; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        if(min != i) {
            t = a[i];
            a[i] = a[min];
            a[min] = t;
        }
    }
}
 */

/* 插入排序
void insert(int a[N+1],int x)
{
    int i = N - 1;
    while (i >= 0 && a[i] > x) {
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = x;
}
 */
