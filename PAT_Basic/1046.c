#include <stdio.h>

int main() {
    int num, i;
    int a = 0, b = 0;
    int a1[101],a2[101],b1[101],b2[101];

    scanf("%d", &num);
    for (i=0; i<num; i++) {
        scanf("%d %d %d %d", &a1[i], &a2[i], &b1[i],&b2[i]);
        if (a2[i] == a1[i] + b1[i] && b2[i] != a1[i] + b1[i])
            b++;
        else if (b2[i] == a1[i] + b1[i] && a2[i] != a1[i] + b1[i])
            a++;
    }
    printf("%d %d",a, b);
    return 0;
}