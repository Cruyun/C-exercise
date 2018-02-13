#include <stdio.h>

int main() {
    int g1,g2;
    int s1,s2;
    int k1,k2;
    int sum1,sum2;

    scanf("%d.%d.%d %d.%d.%d", &g1,&s1,&k1,&g2,&s2,&k2);
    sum1=29*17*g1+29*s1+k1;
    sum2=29*17*g2+29*s2+k2;

    if(sum1>sum2){
        int n1=29+k1-k2;
        int n2;
        if(n1<29)
            n2=17+s1-s2-1;
        else n2=17+s1-s2;
        printf("-%d.%d.%d\n",n2>17?g1-g2:g1-g2-1,n2%17,n1%29);
    }
    else{
        int n2;
        int n1=29+k2-k1;
        if(n1<29)
            n2=17+s2-s1-1;
        else
            n2=17+s2-s1;
        printf("%d.%d.%d\n",n2>17?g2-g1:g2-g1-1,n2%17,n1%29);
    }
    return 0;
}