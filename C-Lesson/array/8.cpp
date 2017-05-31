// 将二维数组c[3][4]转换成一维数组a[12]
#include <stdio.h>

int main() {
    int c[3][4], a[12];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", c[i][j]);
            for (int k = 0; k < 12; k++) {
                a[k] = c[i][j];
            }
        }
    }
}
