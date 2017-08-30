// 部分正确 段错误

#include <iostream>
using namespace std;

int main() {
    int n, m[1000];
    cin >> n;

    int i, j, t;
    for (i = 0; i < n; i++)
        cin >> m[i];
    for (i = 1; i < n; i++) {
        for (j = 0; j < n-1; j++) {
            if (m[j] > m[j+1]) {
                t = m[j+1];
                m[j+1] = m[j];
                m[j] = t;
            }

        }
    }

    int len = m[0];
    for (i = 1; i < n; i++)
        len = (len + m[i]) / 2;
    cout << len;
    return 0;
}
