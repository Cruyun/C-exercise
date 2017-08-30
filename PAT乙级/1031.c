#include <stdio.h>

int main() {
    char id[101][18];
    int weight[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char m[]={'1','0','X','9','8','7','6','5','4','3','2'};

    int num, i, j;
    int passCount=0;
    int checkNum=0;
    int sum=0;
//    int flag=0;

    scanf("%d", &num);

    for(i=0;i<num;i++){
        scanf("%s",id[i]);
    }
    for(i=0;i<num;i++){
        sum=0;
        for(j=0;j<17;j++){
            sum+=(id[i][j]-'0')*weight[j];
        }
//        printf("sum%d\n",sum);
        checkNum=sum%11;
//        printf("checkNum%d\n",checkNum);
//        printf("m[checkNum]:%c\n",m[checkNum]);
//        printf("id[i][17]%c\n",id[i][17]);
        if(m[checkNum]==id[i][17]) {
            passCount++;
//            flag=1;
        }
        else{
            for(j=0;j<18;j++){
                printf("%c",id[i][j]);
            }
            printf("\n");
        }
//        printf("flag%d\n",flag);
//        printf("\n");
    }

//    printf("%d",passCount);
    if(passCount==num)
        printf("All passed");
    return 0;
}