// 最后一个测试点提醒了思路上的一个缺陷。
// 不能只用最大的一个数去和小的数*p比较，因为倒数第二大的数可能也会比小的数*p比大
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long long p;
    cin >> N >> p;

    long long n[100000];
    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }

    sort(n, n+N);

    int fail = 0;
//    for (int j = 0; j < N; j++) {
//        for (int i = j + fail; i < N; ++i) {
//            if (n[i] > n[j] * p)
//                break;
//            fail++;
//        }
//
//    }
    for (int i = 0; i < N; i++) {
        int j = upper_bound(n+i+1, n+N, n[i]*p) - n;
        if (fail < j-i) {
            fail = j-i;
        }
    }

    cout << fail;
    return 0;
}