/* 动态规划求0-1背包问题的最优解 */
#include <iostream>
using namespace std;
int KnapSack(int w[], int v[], int n);

int main() {
  int w[5] = {3, 2, 1, 4, 5}; // 物品重量
  int v[5] = {25, 20, 15, 40, 50}; //价值
  cout << "result: " << KnapSack(w, v, 5) << endl;
  return 0;
}

int KnapSack(int w[], int v[], int n) {
  const int C = 6; // 背包容量
  int i, j;
  int a[n+1][C+1];
  int x[] = {-1};
  for (i = 0; i <= n; i++) {
    a[i][0] = 0;
  }
  for (j = 0; j<= C; j++) {
    a[0][j] = 0;
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= C; j++) {
      if (j < w[i]) {
        a[i][j] = a[i - 1][j];
      } else {
        a[i][j] = (a[i - 1][j] > a[i - 1][j - w[i]] + v[i]) ?  a[i - 1][j] : (a[i - 1][j - w[i]] + v[i]);
      }
    }
  }
  for (j = C, i = n; i > 0; i--) {
    if (a[i][j] > a[i - 1][j]) {
      x[i] = 1;
      j = j - w[i];
    } else {
      x[i] = 0;
    }
  }
  return a[n][C];
}