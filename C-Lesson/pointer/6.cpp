#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char str[100];
    char *p = str;
    scanf("%s", str);
    while(*p != 0){
        printf("%c ", *p++);
    }
    printf("\n");
}
