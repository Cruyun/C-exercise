// 键盘输入某串，求字符ASC码之和。
#include <stdio.h>
#include <cstring>

int main()
{
    char c[40];
    scanf("%s", c);
    int len = strlen(c), sum;

    for (int i = 0; i < len; i++) {
        sum += (int) c[i];
    }

    printf("%d", sum);
}
