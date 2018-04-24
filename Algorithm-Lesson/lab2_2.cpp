#include <iostream>
using namespace std;

int coinSum(int coins[], int n);
int cmp2Coins(int coins[], int real);
int cmp3Coins(int coins[]);
int cmpCoins(int toatal[], int a[], int b[], int c[], int d[], int n);
void allot(int *total, int* a, int* b, int* c, int n);

int main() {
  int temp = 0;
  int n;
  cin >> n;
  int total[n];                                              //输入的总硬币
  int a[15];                                                 //第一堆硬币
  int b[15];                                                 //第二堆硬币
  int c[15];                                                 //第三堆硬币
  int d[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  cout << "请输入硬币重量" << endl;
  for (int i = 0; i < n; i++) {
    cin >> total[n];
  }
  temp = cmpCoins(total, a, b, c, d, n);
  cout << "假币是:" << temp; 
  return 0;
}

int coinSum(int coins[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += coins[i];
  }
  return sum;
}

int cmp2Coins(int coins[], int real) {
  return coins[0] == real ? coins[1] : coins[0];
}

int cmp3Coins(int coins[]) {
  return coins[0] == coins[1] ? coins[2] : (coins[0] == coins[2] ? coins[1] : coins[0]);
}

void allot(int *total, int *a, int *b, int *c, int *d, int n) {
  cout << "分组：" << endl;
  int i, j, k, w;
  i = (n - n % 3) / 3; // 每一堆硬币
  j = n % 3; // 余数堆硬币

  for (k = 0; k < i; k++) {
    *(a + w)= total[i];
    w++;
  }
  cout << "第一堆硬币有" << k << "枚" << endl;

  w = 0;
  for (k = i; k < 2 * i; k++) {
    *(b + w) = total[i];
    w++;
  }
  cout << "第二堆硬币有" << w << "枚" << endl;

  w = 0;
  for (k = 2 * i; k < 3 * i; k++) {
    *(c + w) = total[i];
    w++;
  }
  cout << "第三堆硬币有" << w << "枚" << endl;

  w = 0;
  if (j != 0) {
    for (k = 3 * i; k < n; k++) {
      *(d + w) = total[i];
      w++;
    }
    cout << "第三堆硬币有" << w << "枚" << endl;
  } else {
    *(d + i) = 0;
    cout << "第三堆硬币有0枚" << endl;
  }
}

int cmpCoins(int total[], int a[], int b[], int c[], int d[], int n) {
  int fake = 0;
  allot(total, a, b, c, d, n);

  int m = (n - n % 3) / 3;
  int y = n % 3;
  int a_sum = coinSum(a, m);
  cout << "第一堆硬币总质量为：" << a_sum << endl;
  int b_sum = coinSum(b, m);
  cout << "第二堆硬币总质量为：" << b_sum << endl;
  int c_sum = coinSum(c, m);

  if (a_sum == b_sum) {
    // a == b, 计算第三堆
    // c_sum = coinSum(c, m);
    cout << "第三堆硬币总质量为：" << c_sum << endl;
    // a == c, 假币在 d 中
    if (a_sum == c_sum) {
      cout << "第一堆硬币总质量等于第三堆硬币总质量,则假币在余数堆中" << endl;
      if (y == 1) {
        return d[0];
      } else if (y == 2) {
        fake = cmp2Coins(d, a[0]);
      } else if (y == 3) {
        fake = cmp3Coins(d);
      } else {
        return cmpCoins(d, a, b, c, d, y);
      }
    } else {
      // a != c, 假币在 c 中
      cout << "第一堆硬币总质量不等于第三堆硬币总质量,则假币在第三堆中" << endl;
      if (m == 1) {
        return c[0];
      } else if (m == 2) {
        fake = cmp2Coins(c, a[0]);
      } else if (m == 3) {
        fake = cmp3Coins(c);
      } else {
        return cmpCoins(c, a, b, c, d, m);
      }
    }
  } else if (a_sum != b_sum && a_sum != c_sum) {
    // 假币在 a 中
    cout << "第一堆硬币总质量不等于第三堆硬币总质量,则假币在第三堆中" << endl;
    if (m == 1) {
        return a[0];
      } else if (m == 2) {
        fake = cmp2Coins(a, b[0]);
      } else if (m == 3) {
        fake = cmp3Coins(a);
      } else {
        return cmpCoins(a, a, b, c, d, m);
      }
  } else if (a_sum != b_sum && a_sum == c_sum) {
    // 假币在 b 中
    cout << "第一堆硬币总质量等于第三堆硬币总质量,则假币在第二堆中" << endl;
    if (m == 1) {
        return b[0];
      } else if (m == 2) {
        fake = cmp2Coins(b, a[0]);
      } else if (m == 3) {
        fake = cmp3Coins(b);
      } else {
        return cmpCoins(b, a, b, c, d, m);
      }
  }
}