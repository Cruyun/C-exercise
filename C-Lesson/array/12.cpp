//12．(15分)通过赋初值按行顺序给2×3的二维数组赋予2、4、6、…等偶数，然后按列的顺序输出该数组。试编程。

#include <stdio.h>

int main() {
    int num[3][2]={{2,4},{6,8},{10,12}};
    int i,j;

    for(i=0;i<2;i++){
        for (j = 0; j <3; j++) {
            printf("%d\n",num[j][i]);
        }
    }

    return 0;
}
