// 编写程序，将字符串中的第m个字符开始的全部字符复制成另一个字符串。
// 要求在主函数中输入字符串及m的值并输出复制结果，在被调用函数中完成复制。
#include <stdio.h>
#include <string.h>

void Replace(char *original, char *r, int start) {
    if (original == NULL || r == NULL || start < 0) {
        return;
    }

    int i = 0;
    while (original[i + start] != '\0' && r[i] != '\0')
    {
        original[start + i] = r[i];
        i++;
    }

    original[start + i] = '\0';

}
int main()
{
    char str[1024] = {0};       // 待复制的字符串
    char replace[1024] = {0};   // 要替换成什么
    int m = 0;                  // 第几个字符

    printf("请输入源字符串:");
    scanf("%s", str);
    printf("请输入要替换成什么字符串:");
    scanf("%s", replace);
    printf("请输入从第几位开始替换:");
    scanf("%d", &m);
    printf("开始替换......\n");
    Replace(str, replace, m);
    printf("替换完成，结果为:%s\n", str);

    return 0;
}
