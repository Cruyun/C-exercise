// 分治法求解最近点对问题
#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

#define MIN 10000
#define N 10
using namespace std;

struct point{
  int x, y;
};

void time_counter(double (*func)(point*, int, int), int *arr, int n, int m, string method);

bool cmp (point a, point b) {
  return a.y > b.y;
}

void time_counter(double (*func)(point*, int, int), point *arr, int n, int m, string method) {
  clock_t start, end;
  start  = clock();
  cout << "最近点对距离为" << func(arr, n, m) << endl;
  end = clock();

  double time_used = end - start;
  cout << method << "用时" << time_used << endl;
}

double Distance(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double Cloest(point S[], int low, int high) {
  double d1, d2, d3, d;
  int mid, i, j, index;
  point P[N];
  if (high - low == 1) {
    return Distance(S[0], S[1]);
  }
  if (high - low == 2) {
    d1 = Distance(S[low], S[low + 1]);
    d2 = Distance(S[low + 1], S[high]);
    d3 = Distance(S[low], S[high]);
    if ((d1 < d2) && (d1 < d3)) {
      return d1;
    } else if (d2 < d3) {
      return d2;
    } else {
      return d3;
    }
  }

  mid = (low + high) / 2;
  d1 = Cloest(S, low, mid);
  d2 = Cloest(S, mid + 1, high);
  if (d1 <= d2) {
    d = d1;
  } else {
    d = d2;
  }
  
  index = 0;
  for (i = mid; (i >= low) && (S[mid].x - S[i].x < d); i--) {
    P[index++] = S[i];
  }
  for (i = mid + 1; (i <= high) && (S[i].x - S[mid].x < d); i++) {
    P[index++] = S[i];
  }
  sort(P, P + index - 1, cmp);
  for (i = 0; i < index; i++) {
    for (j = i + 1; j < index; j++) {
      if (P[j].y - P[i].y >= d) {
        break;
      } else {
        d3 = Distance(P[i], P[j]);
        if (d3 < d) d = d3;
      }
    }
  }

  return d;
}
int main() {
  point S[10] = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9,9}};
  // cout << "min distance" << Cloest(S, 0, 9);
  time_counter(Cloest, S, 0, 9, "分治法");

  return 0;
}