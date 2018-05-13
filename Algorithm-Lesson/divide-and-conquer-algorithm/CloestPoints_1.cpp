// 蛮力法求解最近点对问题
#include <iostream>
#include <cmath>
#define MIN 10000
using namespace std;

struct point{
  int x, y;
};

double Distance(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double Cloest(point S[], int low, int high) {
  double d = MIN; // min distance
  if (high - low == 1) {
    d = Distance(S[0], S[1]);
  } else {
    for (int i = low; i < high; i++) {
      for (int j = i + 1; j < high; j++) {
        double d0 = Distance(S[i], S[j]);
        cout << i << " " << j << " " << d0 << endl;
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
  cout << "min distance" << Cloest(S, 0, 9);
  return 0;
}