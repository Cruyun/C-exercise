// 通过指针数组p和一维数组a构成一个3×2的二维数组，并为a数组赋初值2、4、6、8…。
// 要求先按行的顺序输出此二维数组，然后再按列的顺序输出它。试编程。
#include <stdio.h>

int main() {
    int a[3][2] = {2, 4, 6, 8, 10, 12};
    int *pa[3] = {a[0], a[1], a[2]};
    int *p = a[0];
    int i;
    for (i = 0; i < 3; i++) {
        printf("%d, %d, %d\n", a[i][2 - i], *a[i], *(*(a + i) + i));
    }
    for (i = 0; i < 2; i++) {
        printf("%d, %d, %d\n", *pa[i], p[i], *(p + i));
    }
}
