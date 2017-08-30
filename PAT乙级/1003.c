#include <stdio.h>
#include <string.h>

int main() {
    int n,i;
    int a,b,c;
    char s[101];
    char * p;

    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%s", &s);
        p = s;
        a = 0,b = 0,c = 0;
        if (!strcmp(s,"PAT")) {
            printf("YES\n");
            continue;
        }
        while (*p == 'A') {
            a++;
            p++;
        }
        if (*p == 'P') {
            p++;
            while (*p == 'A') {
                b++;
                p++;
            }
            if (*p == 'T') {
                p++;
                while (*p == 'A') {
                    c++;
                    p++;
                }
                if (!(*p) && b > 0 && c == a * b) {
                    printf("YES\n");
                    continue;
                }
            }
        }
        printf("NO\n");
    }
    return 0;
}