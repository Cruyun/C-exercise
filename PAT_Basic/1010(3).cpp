#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int flag = 1;
    int a, a1;
    int b, b1;

    while (scanf("%d %d", &a, &b) != EOF) {
        a1 = a * b;
        b1 = b - 1;
        if (flag) {
            if (b1 != -1) {
                printf("%d %d", a1, b1);
                flag = 0;
            }
        } else {
            if (b1 != -1) {
                printf(" %d %d",a1, b1);
            }
        }
        if (flag)
            printf("0 0");
    }
    return 0;
}