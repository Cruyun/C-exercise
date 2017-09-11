#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a < b;
}

int main() {
    int n;
    cin >> n;

    int * a = new int [n];
    int * b = new int [n];

    int i, j;

    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (i = 0; i < n -1 && b[i] <= b[i + 1]; i++);
    for (j = i + 1; a[j] == b[j] && j < n; j++);
    if (j == n) {
        cout << "Insertion Sort" << endl;
        sort(a, a+i+2, cmp);
    } else {
        cout << "Merge Sort" << endl;
        int k = 1;
        int flag = 1;
        while (flag) {
            flag = 0;
            for (i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    flag = 1;
                }
            }
            k = k * 2;
            for (i = 0; i < n / k; i++) {
                sort(a + i * k, a + (i + 1) * k, cmp);
            }
            sort(a + n / k * k, a + n, cmp);
        }
    }
    for (j = 0; j < n - 1; j++) {
        cout << a[j] << " ";
    }
    cout << a[n - 1];
    delete [] a;
    delete [] b;
    return 0;

}