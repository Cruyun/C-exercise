#include<stdio.h>
// *
// ***
// *****
// *******
// *********
int main (void)
{
    int a,b,n;
    printf("please input:");
    scanf("%d",&n);
    for(a=0;a<n;a++)
    {
        for(b=0;b<n-a-1;b++)
        printf(" ");
        for(b=0;b<2*a+1;b++)
        printf("*");
        printf("\n");
    }
    return 0;
}
