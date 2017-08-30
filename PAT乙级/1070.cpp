#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    int i;
    cin >> n;

    vector<int> m(n);
    for (i = 0; i < n; i++)
        cin >> m[i];

    sort(m.begin(), m.end());

    int len = m[0];
    for (i = 1; i < n; i++)
        len = (len + m[i]) / 2;
    cout << len;
    return 0;
}