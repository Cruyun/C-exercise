#include<stdio.h>

float f2(int n)
{
    if(n==1)
        return n;
    else
        return n*f2(n-1);
}
float f1(int x,int n)
{
    if(n==1)
        return x;
    else
        return x*f1(x,n-1);
}
main()
{
float exp=1.0;
int n,x;
printf("Input a number:");
scanf("%d",&x);
printf("%d\n",x);
exp=exp+x;
for(n=2;n<=19;n++)
exp=exp+f1(x,n)/f2(n);
printf("\nThe is exp(%d)=%8.4f\n",x,exp);
}
