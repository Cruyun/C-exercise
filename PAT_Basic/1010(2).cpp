// 运行超时
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n,e;
    int flag = 0;
    while (scanf("%d %d", &n, &e)) {
        if (n * e) {
            if (flag)
                printf(" ");
            else
                flag = 1;
            printf("%d %d",n*e, e-1);
        }
    }
    if (!flag)
        printf("0 0");
    return 0;
}