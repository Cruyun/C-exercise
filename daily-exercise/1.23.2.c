/*
  ��ȡ������������ʾ���ǵ��˺�����
  */

#include <stdio.h>

int main(void)
{
    int a, b;

    puts("��������������");
    printf("����a"); scanf("%d", &a);
    printf("����b"); scanf("%d", &b);

    printf("a����b��%d��%d��\n", a / b, a & b);

    return 0;
}
