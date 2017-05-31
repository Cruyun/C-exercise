//13．(10分)若有说明：int a[2][3]={{1,2,3},{4,5,6}};现要将a的行和列的元素互换后存到另一个二维数组b中。试编程。

#include <stdio.h>

int main() {
    int a[2][3]={{1,2,3},{4,5,6}};
    int b[3][2];
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            b[j][i]=a[i][j];
        }
        printf("%d %d %d\n",b[0][i],b[1][i],b[2][i]);
    }
    return 0;
}
