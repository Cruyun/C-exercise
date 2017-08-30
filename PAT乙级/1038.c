#include <stdio.h>
//段错误，cpp版没有问题
int main() {
    long int num;
    int i, j;
    int score[1000];
    int findscore[1000];
    int find;
    int match[1000]={0};

    scanf("%ld", &num);
    for(i=0; i<num; i++) {
        scanf("%d",&score[i]);
    }

    scanf("%d", &find);
    for(i=0; i<find; i++) {
        scanf("%d", &findscore[i]);
    }

    for (i=0; i<find; i++) {
        for (j=0; j<num; j++) {
            if (findscore[i] == score[j])
                match[i]++;
        }
        if (i != find-1)
            printf("%d ",match[i]);
        else
            printf("%d",match[i]);
    }

    return 0;
}

//int main() {
//    long int N;
//    int i;
//    int score[1000]={0};
//    int list;
//    int find[1000];
//    int n;
//
//    scanf("%ld", &N);
//    for (i = 0; i < N; i++) {
//        scanf("%d", &list);
//        score[list]++;
//    }
//
//    scanf("%d", &n);
//    for (i = 0; i < n; i++) {
//        scanf("%d", &find[i]);
//    }
//
//    for (i = 0; i < n -1; i++) {
//        printf("%d ", score[find[i]]);
//    }
//
//    printf("%d", score[find[i]]);
//    return 0;
//}