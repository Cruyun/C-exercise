#include <stdio.h>
#include <string.h>
int main() {
    char A[1005] = {'0'};
    int B;
    int R = 0;
    int len, i, d, e;

    scanf("%s%d", A,&B);
    len = strlen(A);

    int Q[len];
    for (i = 0; i < len; i++) {
        Q[i] = (R * 10 + (A[i] - '0')) / B;
        R = (R * 10 + (A[i] - '0')) % B;
    }
    int start = 0;
    for(i = 0; i < len; i++){
        if(Q[i] != 0){
            start = i;
            break;
        }
    }
    for(i = start; i < len; i++){
        printf("%d",Q[i]);
    }
    printf(" %d\n",R);
    return 0;
}