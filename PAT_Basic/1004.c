#include <stdio.h>
#include<string.h>

int main() {
    int num;
    char name[200][20];
    char id[200][20];
    int score[200];
    char max_name[20];
    char min_name[20];
    char max_id[20];
    char min_id[20];
    int i;


    scanf("%d", &num);
    for(i=0;i<num;i++){
        scanf("%s %s %d",name[i],id[i],&score[i]);
    }

    int max_score=score[0];
    int min_score=score[0];
    for(i=0;i<num;i++){
        if(score[i]>=max_score){
            max_score=score[i];
            strcpy(max_name,name[i]);
            strcpy(max_id,id[i]);
        }
        if(score[i]<=min_score) {
            min_score = score[i];
            strcpy(min_name, name[i]);
            strcpy(min_id, id[i]);
        }
    }
    printf("%s %s\n",max_name,max_id);
    printf("%s %s\n",min_name,min_id);
    return 0;
}
