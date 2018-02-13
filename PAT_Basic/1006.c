#include <stdio.h>

int main(void) {
    int x; //输入的整数
    int h = 0; //百位
    int t = 0;  // 十位
    int p;  //个位
    int b, s, n;

    scanf("%d", &x);
    h = x / 100;
    t = (x - (100 * h)) / 10;
    p = x - (100 * h + 10 * t);

    for (b = 0; b < h ; b++) {
        printf("B");
    }
    for (s = 0; s < t; s++){
        printf("S");
    }
    for (n = 1; n <= p; ++n) {
        printf("%d", n);
    }
    return 0;
}