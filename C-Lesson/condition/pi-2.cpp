#include<stdio.h>

void main()
{
    int n = 1;
    float temp =1.0;
    float sum = 0.0;

    while(temp >= 0.000001){
        temp = (float)1 / ( 2 * n - 1);
        if( n % 2 == 1)
            sum += temp;
        else sum -= temp;
        n ++;
    }
    printf("Pi=%f\n", sum * 4);
}
