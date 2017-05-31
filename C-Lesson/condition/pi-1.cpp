#include<stdio.h>

void main()
{
    int n;
    float temp =1;
    float sum = 0.0;

    for(n = 1; temp >= 0.000001; n++){
        temp = (float)1 / ( 2 * n - 1);
        if( n % 2 == 1)
            sum += temp;
        else sum -= temp;
    }
    printf("Pi=%f\n", sum * 4);
}
