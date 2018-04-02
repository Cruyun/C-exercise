//实现查找8枚硬币中的假币位置，并且判断假币比真币重还是轻
#include <iostream>
using namespace std;

int coinSum(int a[], int low, int high);
void eightCoins(int coins[]);
void cmpCoins(int a, int b, int real, int index1, int index2);
void nCoins(int coins[]);

int main() {
    int coins[8] = {0};

    cout << "输入硬币重量:";
    for (int i = 0; i < 8; i++) {
        cin >> coins[i];
    }
    eightCoins(coins);

    return 0;
}

int coinSum(int a[], int low, int high) {
    int sum = 0;
    for (int i = low; i <= high; i++) {
        sum += a[i];
    }
    return sum;
}

void eightCoins(int coins[]) {
    int abc = coinSum(coins, 0, 2);
    int def = coinSum(coins, 3, 5);
    int a = coins[0];
    int b = coins[1];
    int c = coins[2];
    int d = coins[3];
    int e = coins[4];
    int f = coins[5];
    int g = coins[6];
    int h = coins[7];

    int ae = a + e;
    int bd = b + d;

    if (abc > def) {
        if (ae > bd) {
            cmpCoins(a, d, h, 1, 4);
        } else if (ae == bd) {
            cmpCoins(c, f, h, 3, 6);
        } else {
            cmpCoins(b, e, h, 2, 5);
        }
    } else if (abc == def) {
       if (a == g) {
          if (a < h) {
            cout << "h 是较重的假币";
          } else {
            cout << "h 是较轻的假币";
          }
       } else {
          if (a < g) {
            cout << "g 是较重的假币";
          } else {
            cout << "g 是较轻的假币";
          }
       }
    } else {
       if (ae > bd) {
          cmpCoins(b, e, h, 2, 5);
       } else if (ae == bd) {
          cmpCoins(c, f, h, 3, 6);
       } else {
         cmpCoins(a, d, h, 1, 4);
       }
    }
}

void cmpCoins(int a, int b, int real, int index1, int index2) {

  if (a == real) {
     if (b > real) {
       cout << index2 <<" 是较重的假币";
     } else {
       cout << index2 <<" 是较轻的假币";
     }
  } else {
    if (a > real) {
       cout << index1 <<" 是较重的假币";
     } else {
       cout << index1 <<" 是较轻的假币";
     }
  }
}
