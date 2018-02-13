#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define maxNum 120000
#define PrimeNum 10000

int prime[PrimeNum];
int visit[maxNum];

void initPrimes() {
    int i, j;
    int count = 0;
    for (i = 2; (i < maxNum) && (count < PrimeNum); i++) {
        if (!visit[i]) {
            prime[count] = i;
            count++;
        }
        for (j = 0; (j < count) && (i * prime[j] < maxNum); j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main() {
    memset(prime,0, sizeof(prime));
    memset(visit,0,sizeof(visit));
    initPrimes();
    int M, N;
    int i;
    int count = 0;
    scanf("%d %d", &M, &N);
    for (i = M-1; i < N; i++) {
        if (count < 9) {
            if (count)
                printf(" ");
            printf("%d", prime[i]);
            count++;
        } else {
            printf(" %d\n", prime[i]);
            count = 0;
        }
    }
    return 0;
}