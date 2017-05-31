#include<stdio.h>

void main()
{
	int n = 1;
	float temp;
	float sum = 0.0;

	do{
		temp = (float)1 / ( 2 * n - 1);
		if( n % 2 == 1)
			sum += temp;
		else sum -= temp;
		n ++;
	}while(temp >= 0.000001);
		printf("Pi=%f\n", sum * 4);
}