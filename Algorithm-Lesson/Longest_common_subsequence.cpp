#include <iostream>
using namespace std;
const int M = 9;
const int N = 6;
int L[M+1][N+1];
int S[M+1][N+1];

int CommonOrder(char x[], char y[], char z[]);
int main() {
  char x[M+1] = {'x', 'a', 'c', 'b', 'b', 'a', 'b', 'd', 'b', 'b'};
  char y[N+1]= {'x', 'a', 'b', 'c', 'b', 'd', 'b'};
  char z[] = {0};
  cout << CommonOrder(x, y, z);
}

int CommonOrder(char x[], char y[], char z[])
{
  int i, j, k;
  for (j = 0; j <= N; j++) {
    L[0][j] = 0;
    S[0][j] = 0;
  }
  for (i = 0; i <= M; i++) {
    L[i][0] = 0;
    S[i][0] = 0;
  }
  for (i = 1; i <= M; i++) {
    for (j = 1; j <= N; j++) {
      if (x[i] == y[j]) {
        L[i][j] = L[i - 1][j - 1] + 1;
        S[i][j] = 1;
      } else {
          if (L[i][j - 1] >= L[i - 1][j]) {
              L[i][j] = L[i][j - 1];
              S[i][j] = 2;
          } else {
              L[i][j] = L[i - 1][j];
              S[i][j] = 3;
          }
      }
      cout << "L " << L[i][j] << " S " << S[i][j] << endl;
    }
  }
  i = M;
  j = N;
  k = L[M][N];
  while (i > 0 && j > 0) {
    if (S[i][j] == 1) {
      z[k] = x[i];
      k--;
      i--;
      j--;
    } else if (S[i][j] == 2) {
      j--;
    } else {
      i--;
    }
  }

  for (k = 1; k <= L[M][N]; k++) {
    cout << z[k] << endl;
  }
  return L[M][N];
}