#include <stdio.h>

int main() {
    char a;
    int b=0;
    char *p;

    scanf("%s",&a);
    p=&a;
    while(*p){
        b=b*10+(*p++)-48;
    }

    printf("%d",b);
    return 0;
}
