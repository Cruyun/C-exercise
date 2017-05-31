// 将两个字符串连接起来(不用strcat)。
#include <stdio.h>

int main()
{
    int i, j;
    char a[40], b[40], c[80];
    printf("Please input string1: \n");
    gets(a);
    printf("Please input string2: \n");
    gets(b);

    for (i = 0; a[i] != '\0'; i++) {
        c[i] = a[i];
    }
    for (j = 0; b[i] != '\0'; j++) {
        c[i + j] = b[j];
    }
    c[i + j] = '\0';
    puts(c);
    return 0;
}