/* 钢条切割问题
给定一条长度为 n 的钢条和一个价格表 pi，求切割方案，收益 rn 最大
自顶向上法伪代码：BOTTOM-UP-CUT-ROD(p,n)
let r[0..n]and s[0..n]be new arrays
r[0] = 0
for j = 1 to n
  q = -∞
  for i = 1 to j
    if q < p[i] + p[j - i]
      q = p[i] + p[j - i]
      s[j] = i
    r[j]  = q
return r and s

打印切割方案：PRINT-CUT-ROD-SOLUTION(p,n)
(r, s) = BOTTOM-UP-CUT-ROD(p,n)
while n > 0
  print s[n]
  n = n - s[n]
*/
#include <cstdio>
using namespace std;

void cut(int *p, int *s, int *r, int n);
void print(int *p, int *s, int *r, int n);
int main() {
  // int n = 10;
  int n;
  scanf("%d", &n);
  int p[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30}; // 价格表
  int *s = new int[n + 1];
  int *r = new int[n + 1];
  print(p, s, r, n);
  return 0;
}

void cut(int *p, int *s, int *r, int n) {
  r[0] = 0;
  for (int j = 1; j <= n; j++) {
    int q = -1;
    for (int i = 1; i <= j; i++) {
      if (q < p[i - 1] + r[j - i]) {
        q = p[i - 1] + r[j - i];
        s[j] = i;
      }
    }
    r[j] = q;
  }
}

void print(int *p, int *s, int *r, int n) {
  cut(p, s, r, n);
  printf("长度为%d的钢条最大收益为%d\n", n, r[n]);
  printf("最优方案的钢条长度分别为:");
  while(n > 0) {
    printf("%d ", s[n]);
    n = n - s[n];
  }
}