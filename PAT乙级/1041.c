#include <stdio.h>

int main() {

    int total;

    scanf("%d",&total);

    long long int id[total];
    int test1[total];
    int test2[total];

    int num;
    int seek;
    int i,j;


    for (i = 0; i <total ; i++) {
        scanf("%lld %d %d",&id[i],&test1[i],&test2[i]);
    }
    scanf("%d", &num);

    for (j = 0; j <num; j++) {
        scanf("%d",&seek);
        for (i = 0; i <total; i++) {
            if(seek==test1[i])
                printf("%lld %d\n",id[i],test2[i]);
        }
    }
    return 0;
}