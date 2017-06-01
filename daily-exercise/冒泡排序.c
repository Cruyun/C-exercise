#include <stdio.h>
#define NUM 10

void main()
{
  int a[NUM], i, j, t;

  printf("input %d numbers: \n", &NUM);
  for (i = 0;i < NUM; i++)
  scanf("%d",&a[i]);

  for (i = 1; i < NUM; i++){
    for (j = 0; j < NUM -1; j++){
      if (a[j] > a[j+1]){
        t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
      }
    }
  }

  printf("the sorted numbers:\n");
  for (i = 0; i < NUM; i++){
    printf("%d", a[i]);
  }
}
