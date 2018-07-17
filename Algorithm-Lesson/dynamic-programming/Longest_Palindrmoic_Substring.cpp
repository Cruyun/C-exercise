// 最长回文子串
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestPalSub(char *str)
{
  int n = strlen(str);
  bool table[n][n];
  memset(table, 0, sizeof(table));

  int maxLen = 1;
  int i, j, k;
  int start = 0;

  for (i = 0; i < n; i++) {
    table[i][i] = true;
  }

  for (i = 0; i < n - 1; i++) {
    if (str[i] == str[i + 1]) {
      table[i][i + 1] = true;
      start = i;
      maxLen = 2;
    }
  }

  for (k = 3; k <= n; k++) {
    for (i = 0; i < n - k + 1; i++) {
      int j = i + k - 1;
      if (table[i + 1][j - 1] == true && str[i] == str[j]) {
        table[i][j] = true;
        if (k > maxLen) {
          start = i;
          maxLen = k;
        }
      }
    }
  }

  for( i = start; i <= start + maxLen - 1; ++i ) {
    printf("%c", str[i]);
  }
  return maxLen;
}

int main()
{
  char str[] = "abcda";
  printf("%d", longestPalSub(str));
}