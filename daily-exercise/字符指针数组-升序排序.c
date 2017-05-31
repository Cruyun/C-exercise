#include <stdio.h>
#include <string.h>

void main ()
{
  int i, j, k;
  char *pcity[] = {"wuhan", "beijing", "shanghai", "tianjin", "guangzhou", ""};
  char *ptemp;

//选择排序
  for (i=0; strcmp(pcity[i], "") != 0; i++){
    k=i;
    for (j = i + 1; strcmp(pcity[j], "") != 0; j++){
      if (strcmp(pcity[k], pcity[j])>0)
        k = j;
    }
    if (k != i){
      ptemp = pcity[i];
      pcity[i] = pcity[k];
      pcity[k] = ptemp;
    }
  }

  for (i = 0; strcmp(pcity[i], "")!= 0; i++)
  printf("%s ", pcity[i]);
  printf("\n");
}
