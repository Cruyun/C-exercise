//输入的数为列，该数减半向上取整为行
#include <stdio.h>

int main() {
    int n;
    char a;
    int col;
    int i;
    int j;

    scanf("%d %c",&n,&a);
    col=(n+1)/2;//列数

    for(i=0;i<col;i++){
       for(j=0;j<n;j++){
           if(i==0||i==col-1||j==0||j==n-1)
               printf("%c",a);
           else printf(" ");
       }
        printf("\n");
    }

    return 0;
}