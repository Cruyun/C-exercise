#include <stdio.h>
#include <string.h>
int main() {
    char A[1000];
    int B;
    int Q[1000];
    int R;
    int len,i;
    int d,e;

    scanf("%s %d", A,&B);
    len=strlen(A);
    for (i = 0; i <len; i++) {
        d=((A[i]-'0')*10 + (A[i+1]-'0'))/B;
        R=((A[i]-'0')*10 + (A[i+1]-'0'))%B;
        Q[i]=d;
        A[i+1]=R+'0';
        if(i==len-2)
            break;
    }

    for(i=0;i<len-1;i++){
        printf("%d",Q[i]);
    }
    printf(" %d",R);
    return 0;
}