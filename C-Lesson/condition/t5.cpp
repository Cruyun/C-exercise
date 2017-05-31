//请编程序：根据以下函数关系，对输入的每个x值，计算出相应的y值。

#include <stdio.h>

int main()
{
    float x;
    double y;

    printf("x:");
    scanf("%f", &x);

    if(x <0.0) y = 0.0;
    if (x > 0.0 && x <= 10.0) y =x;
    if (x>10.0 && x<= 20.0) y =10;
    if (x >20.0 && x<40.0) y = -0.5 * x+20.0;

    printf("y:%.6f", y);
}
