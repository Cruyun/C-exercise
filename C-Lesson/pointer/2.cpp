#include <stdio.h>

int lenstr(const char *str);
int main() {
    char num[1000];
    gets(num);
    printf("%d",lenstr(num));
    return 0;
}

int lenstr(const char *str){
    int i=0;
    while (str[i++]);
    return i-1;
}
