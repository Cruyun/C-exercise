#include <stdio.h>

int main() {
    long t1,t2;
    int h,m,s;
    long seconds;
    long t;

    scanf("%ld %ld",&t1,&t2);

    t=t2-t1;
//    seconds=(int)(((t2-t1)/100)+0.5);

    if(t%100>=0 && t%100<=49)
        seconds=t/100;
    else if(t%100>=50 && t%100<=99)
        seconds = t/100 +1;
    h=seconds/3600;
    m=(seconds-h*3600)/60;
    s=seconds-h*3600-m*60;

    printf("%02d:%02d:%02d",h,m,s);
    return 0;
}