//18．(10分)数组a包括10个整数，把a中所有的后项除以前项之商取整后存入数组b，并按每行3个元素的格式输出数组b。试编程。

#include <stdio.h>
void main()
{   int a[10],b[10];
    int i;

    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    for(i=1;i<10;i++)
        b[i]=a[i]/a[i-1];
    for(i=1;i<10;i++)
    {
        printf("%d ",b[i]);
        if(i%3==0) printf("\n");
    }
}
