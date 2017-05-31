// 用选择法对10个整数按升序排序
#include<stdio.h>

int main()
{
    int a[10];
    int temp;
    for(int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
        for (int j = i + 1; j < 10; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        printf("%d ", a[i]);
    }
}
