// 注意sort函数的cmp，ort函数的cmp必须按照规定来写，即必须只是 > 或者 <
//比如:
//return a > b;
//return a < b;
//
//而不能是 <= 或者 >= ，（实际上等于号加了也是毫无意义，sort是不稳定的排序），否则可能会出现段错误
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a < b;
}
int main() {
    int n,m(0);
    cin >> n;

    int input[100000], i;

    for (i = 0; i < n; i++) {
        cin >> input[i];
    }

    sort(input, input+n, cmp);

    for (i = 0; i < n; i++) {
        if (input[i] > n - i) {
            m = n - i;
            break;
        }
    }
    cout << m << endl;
    return 0;
}