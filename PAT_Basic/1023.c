#include<stdio.h>

int main()
{
    int num[10];
    int i,j,first;
    int flag=1;

    //从1开始找到数量不为0的数当做第一个数，把数量-1
    for(i=0;i<10;i++)
    {
        scanf("%d",&num[i]);
        if(i&& num[i] && flag)
        {
            first=i;
            num[i]--;
            flag=0;
        }
    }
    printf("%d",first);

    for(i=0;i<10;i++)
    {
        for(j=0;j<num[i];j++)
            printf("%d",i);
    }

    return 0;
}
