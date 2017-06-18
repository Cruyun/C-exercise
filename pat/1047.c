#include <stdio.h>

int main() {
    int team[10000], member, score;
    int a[10000]={0};
    int n, i, max_team, max_score;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d-%d %d", &team[i], &member, &score);
        a[team[i]]+=score;
    }
    i = 0;
    max_team = team[0];
    max_score = a[team[0]];

    for (i = 1; i < n; i++) {
        if (max_score < a[team[i]]) {
            max_score = a[team[i]];
            max_team = team[i];
        }
    }

    printf("%d %d",max_team, max_score);

    return 0;
}