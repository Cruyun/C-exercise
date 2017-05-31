#include <stdio.h>

int main() {
    int i=0,a=0,b=0,c=0,d=0,f=0;
    char *p;
    char s[100];
    gets(s);
    while(s[i]!='\n')
        i++;
    p=s;
    while(*p!='\0') {
        if (*p >= 'A' && *p <= 'Z')
            a++;
        else if (*p >= 'a' && *p <= 'z')
            b++;
        else if (*p >= '0' && *p <= '9')
            c++;
        else if (*p == ' ')
            d++;
        else f++;
        p++;
    }

    printf("UPletter:%d, LowLetter:%d\n",a,b);

    printf("number:%d, other:%d\n",c,f);

    printf("space:%d\n",d);

    return 0;
}
