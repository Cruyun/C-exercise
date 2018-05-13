#include <cstdio>
#include <string>
#include <ctime>
#include <iostream>
using namespace std;

void bruteForce(int arr[], int n);
void divideMethod(int arr[], int n);
void dynamicSolution(int arr[], int n);


int divideSolution(int arr[], int left, int right);
void time_counter(void (*func)(int*, int), int *arr, int n, string method);

int main() {
  int arr[9] = {-2, 1, -3, 4, -1,2, 1, -5, 4};
  int n = 9;
  time_counter(bruteForce, arr, 9, "蛮力法");
  time_counter(dynamicSolution, arr, 9, "动态规划");
  time_counter(divideMethod, arr, 9, "分治法");
  return 0;
}

void time_counter(void (*func)(int*, int), int *arr, int n, string method) {
  clock_t start, end;
  start  = clock();
  func(arr, n);
  end = clock();

  double time_used = end - start;
  cout << method << "用时" << time_used << endl;
}
void divideMethod(int arr[], int n) {
  cout << divideSolution(arr, 0, n - 1) << " ";
}
void dynamicSolution(int arr[], int n) {
  int max = 0;
  int last_max = 0;
  for (int i = 0; i < n; i++) {
    last_max += arr[i];
    if (last_max > max) {
      max = last_max;
    }
    if (last_max < 0) {
      last_max = 0;
    }
  }
  printf("DP:%d ", max);
}

void bruteForce(int arr[], int n) {
  int max = 0;
  for (int i = 0; i < n; i++) {
    int temp = 0;
    for (int j = i; j < n; j++) {
      temp += arr[j];
      if (temp > max) {
        max = temp;
      }
    }
  }
  printf("BF: %d ", max);
}

int divideSolution(int arr[], int left, int right) {
  int sum = 0;
  int midSum = 0;
  int leftSum = 0;
  int rightSum = 0;
  int center, s1, s2, lefts, rights;

  if (left == right) {
    sum = (arr[left] > 0 ? arr[left] : 0);
  } else {
    center = (left + right) / 2;
    leftSum = divideSolution(arr, left, center);
    rightSum = divideSolution(arr, center + 1, right);
    s1 = 0;
    lefts = 0;
    for (int i = center; i >= left; i--) {
      lefts += arr[i];
      if (lefts > s1) {
        s1 = lefts;
      }
    }

    s2 = 0;
    rights = 0;
    for (int j = center + 1; j <= right; j++) {
      rights += arr[j];
      if (rights > s2) {
        s2 = rights;
      }
    }
    midSum = s1 + s2;
    sum = midSum < leftSum ? leftSum : midSum;
    if (sum < rightSum) sum = rightSum;
  }
  return sum;
}