#include <stdio.h>

int main() {
    char num[1000]={0};
    gets(num);

    char *p;
    p=num;
    int i=0;
    while (num[i]!=0){
        printf("%c",p[i]);
        i+=2;
    }
    return 0;
}
