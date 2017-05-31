#include <stdio.h>

int main() {
    int num;
    long a[100];
    long b[100];
    long c[100];
    int i=0;

    scanf("%d", &num);
    for ( i = 0; i < num; i++) {
        scanf("%ld %ld %ld", &a[i],&b[i],&c[i]);
    }
    for (i = 0; i < num; i++) {
        if (a[i]+b[i]>c[i]){
            printf("Case #%d: true\n",i+1);
        }
        else
        {
            printf("Case #%d: false\n",i+1);
        }
    }
    return 0;
}
