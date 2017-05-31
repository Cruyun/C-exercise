#include <stdio.h>
//求1-3+5-7+….-99+101之值。
int main()
{
    int i=1;
    int sum=0;
    int k=1;

    for(i =1;i<=101;i=i+2){
        if(k%2==0)
            sum = sum+i;
        else sum = sum-i;
        k++;
    }
    printf("1-3+5-7+….-99+101=%d", sum);
    return 0;
}
