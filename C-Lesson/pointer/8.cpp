// 编写程序，将字符串computer赋给一个字符数组，然后从第一个字母开始间隔地输出该串，请用指针完成。
#include <stdio.h>
#include <cstring>

int main() {
    char *p = "computer";
    for (int i = 0; i < strlen(p); i += 2) {
        printf("%c", p[i]);
    }
    printf("\n");
    return 0;
}
