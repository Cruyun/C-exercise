#include <stdio.h>
//输出下列图形。
//1  2  3  4  5  6  7  8  9
//2  3  4  5  6  7  8  9
//3  4  5  6  7  8  9
//4  5  6  7  8  9
//5  6  7  8  9
//6  7  8  9
//7  8  9
//8  9
//9

int main()
{
    int i;
    int j;
    for(i =1;i<=9;i++){
        for(j = 1; j<=10-i;j++){
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}
