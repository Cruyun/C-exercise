// 部分正确 17/25
#include <cstdio>
using namespace std;

int main()
{
  double n[1001] = {0.0};
  int k1, k2, i;
  int max_e = 0;

  scanf("%d", &k1);

  for (i = 0; i < k1; i++) {
    int e;
    scanf("%d", &e);
    scanf("%lf", &n[e]);

    if (max_e < e) max_e = e;
  }

  scanf("%d", &k2);
  
  int j = k1;
  for (i = 0; i < k2; i++) {
    int q;
    double p;
    scanf("%d", &q);
    scanf("%lf", &p);
    if (n[q] == 0.0) j++;
    n[q] += p;

    if (max_e < q) max_e = q;
  }

  printf("%d", j);

  for (i = max_e; i >= 0; i--) {
    if (n[i] != 0.0) {
      printf(" %d %.1f", i, n[i]);
    }
  }
  
  return 0;
}