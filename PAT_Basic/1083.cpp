#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    cin >> n;

    int minus[20001] = {0};
    int i;
    for (i = 1; i <= n; i++) {
        int m;
        cin >> m;
        int minus_result = abs(m - i);
        minus[minus_result]++;
    }
    for (i = 20000; i >= 0; i--) {
        if (minus[i] != 0 && minus[i] != 1) {
            cout << i << " " << minus[i] << endl;
        }
    }
    return 0;
}