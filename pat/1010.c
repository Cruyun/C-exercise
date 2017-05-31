#include <stdio.h>

int main() {
    int x[1000];
    int len=0;
    int j=0;
//
//    while(getchar() != '\n'){
//        scanf("%d",&x[j+1]);
//        printf("x[%d]%d\n",j,x[j]);
//        j++;
//    }
    for ( j = 0 ; ;j++) {
        scanf("%d",&x[j]) ;
        if ( getchar() == '\n')
            break ;
//        printf("x[%d]%d\n",j,x[j]);
    }
    len=j;

//printf("len:%d\n",len);

    if(len==1&&x[1]==0)
        printf("0 0");
    else if(len==1 && x[1]!=0)
        printf("%d %d", x[0]*x[1], x[1]-1);
    else if(len>2){
        for (j = 0; j < len-2; j+=2) {
            if ( x[j+1] !=0 && j <= len - 3 )
                printf("%d %d ",x[j]*x[j+1],x[j+1]-1) ;

            else if ( x[j+1] != 0 && j == len -3 && x[len] == 0)
                printf("%d %d",x[j]*x[j+1],x[j+1]-1) ;

            else if (x[j+1] != 0 && j == len -3 && x[len] != 0)
                printf("%d %d ",x[j]*x[j+1],x[j+1]-1) ;
        }
        if ( x[len] != 0 )
            printf("%d %d",x[len -1]*x[len],x[len] - 1);
    }
    return 0;

}
