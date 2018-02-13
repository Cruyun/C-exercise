#include <stdio.h>

int main() {
    int a,b,d;
    int c;
    int i,j;
    int num[50];

    scanf("%d %d %d",&a, &b, &d);
    c=a+b;

    i=0;
    if(c==0)
        printf("0");
    while (c){
        num[i]=c%d;
        c/=d;
        i++;
    }
    for(j=i-1;j>=0;j--){
        printf("%d",num[j]);
    }

    return 0;
}