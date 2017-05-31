//输入三个实数，判断组成三角形形状。若为正三角形则输出1，为等腰三角形则输出2，为任意三角形则输出3，不能构成三角形则输出0
#include <stdio.h>

int main()
{
    int a, b, c;
    int flag;

    printf("输入三角形三边长度（用空格空开）:");
    scanf("%d %d %d", &a, &b, &c);

    if(!(a+b<=c||a+c<=b||b+c<=a)){
        if(a == b || a ==c || b ==c) {
            if (a == b && a ==c)
            flag = 1;
            else flag = 2;
        } else flag = 3;

    } else flag = 0;

   printf("%d", flag);
}
