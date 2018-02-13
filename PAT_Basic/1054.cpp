#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
// 判断：是否是合法数字：整数 和合法小数 -999 ~ 999
// sscanf() – 从一个字符串中读进与指定格式相符的数据
// sprintf() – 字符串格式化命令，主要功能是把格式化的数据写入某个字符串中

int main() {
    int n;
    cin >> n;

    char x[50], y[50];
    double legal, sum = 0.0;

    int count = 0; //count of legal number

    for (int i = 0; i < n; i++) {
        scanf("%s",x);
        sscanf(x, "%lf", &legal);
        sprintf(y,"%.2lf", legal);
        int flag = 0;

        for (int j = 0; j < strlen(x); j++) {
            if (x[j] != y[j])
                flag = 1;
        }
        if (flag || legal < -1000 || legal > 1000) {
            printf("ERROR: %s is not a legal number\n", x);
            continue;
        } else {
            sum += legal;
            count++;
        }
    }

    if (count >= 1) {
        printf("The average of %d number is %.2lf", count, sum / count);
    } else {
        printf("The average of 0 numbers is Undefined");
    }

    return 0;
}