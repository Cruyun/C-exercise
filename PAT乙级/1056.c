#include <stdio.h>

int main() {
    int num[10];
    int sum=0;
    int i,j;
    int n;

   scanf("%d", &n);
   for (i = 0; i<n; i++) {
      scanf("%d", &num[i]);
   }

   for (i = 0; i <= n-2; i++) {
      for (j = i+1; j <= n-1; j++) {
         sum += num[i] * 10 + num[j] + num[j] * 10 + num[i];
      }
   }
   printf("%d", sum);
   return 0;
}
