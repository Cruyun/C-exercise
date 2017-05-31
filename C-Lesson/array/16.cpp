//16．(10分)从键盘输入两个字符串a和b，要求不用库函数strcat把串b的前五个字符连接到串a中；如果b的长度小于5，则把b中的所有元素都连接到a中。试编程。

#include <stdio.h>
int main(void)
{
    char a[128], b[128];
    char *p = a;
    int i;
    printf("请输入字符串a:");
    gets(a);
    printf("请输入字符串b:");
    gets(b);
    while (*p) p++;
    for (i = 0; i < 5; i++)
        p[i] = b[i];
    p[++i] = '\0';
    printf("%s\n", a);
    return 0;
}
