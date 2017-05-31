#include <stdio.h>

#define number 5

void bsort(int a[], int n)
{
  int i, j;

  for (int i = 0; i < n - 1; i++) {
    for (j = n -1; j > i; j --){
      if (a[j - 1] > a[j]) {
        int temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
      }
    }
  }
}
int main(void)
{
  int i;
  int height[number];

  printf("身高%d\n", number );
  for (i = 0; i < number; i++){
    printf("%2d号\n", i + 1 );
    scanf("%d\n", &height[i] );
  }

  bsort (height, number);
  puts("升序");
  for (int i = 0; i < number; i++)
  printf("%2d: %d\n", i + 1, height[i] );

  return 0;
}
