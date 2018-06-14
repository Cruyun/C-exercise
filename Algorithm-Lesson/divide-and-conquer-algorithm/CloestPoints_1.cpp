// 蛮力法求解最近点对问题
#include <iostream>
#include <cmath>
#define MIN 10000
using namespace std;

// void time_counter(double (*func)(point*, int, int), int *arr, int n, int m, string method);

struct point{
  int x, y;
};

double Distance(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void time_counter(double (*func)(point*, int, int), point *arr, int n, int m, string method) {
  clock_t start, end;
  start  = clock();
  cout << "最近点对距离为" << func(arr, n, m) << endl;
  end = clock();

  double time_used = end - start;
  cout << method << "用时" << time_used << endl;
}

double Cloest(point S[], int low, int high) {
  double d = MIN; // min distance
  if (high - low == 1) {
    d = Distance(S[0], S[1]);
  } else {
    for (int i = low; i < high; i++) {
      for (int j = i + 1; j < high; j++) {
        double d0 = Distance(S[i], S[j]);
        if (d > d0) {
          d = d0;
        }
      }
    }
  }

  return d;
}
int main() {
  point S[10] = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9,9}};
  time_counter(Cloest, S, 0, 9, "蛮力法");

  return 0;
}