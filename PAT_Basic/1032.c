#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    int school,score;
    int sort[100001]={0};
    int i;
    int school_max=0;
    int score_max=0;

    for(i=0;i<num;i++){
        scanf("%d %d",&school,&score);
        sort[school]+=score;
        if(sort[school]>=score_max){
            score_max = sort[school];
            school_max = school;
        }
    }
    printf("%d %d",school_max, score_max);
    return 0;
}