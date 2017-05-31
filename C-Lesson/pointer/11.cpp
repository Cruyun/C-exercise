// 编写程序，统计从键盘输入的命令行中第二个参数所包含的英文字符个数。
#include <stdio.h>

int main(int argc,char *argv[]) {
    int count = 0, i;

    for (i = 1; i < argc; i++) {
        printf("%d %s \n", i, argv[i]);
        while (*argv[i]) {
            if ((*argv[i] >= 'a' && *argv[i] <= 'z') || (*argv[i] >= 'A' && *argv[i] <= 'Z')) {
                count++;
                *argv[i]++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
