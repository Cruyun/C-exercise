#include <iostream>
using namespace std;

int main() {
    int n;
    char shape;
    cin >> n >> shape;

    int i, j ,res, count(1);
    while (2 * count * count - 1 <= n) {
        count++;
    }
    count--;
    res = n - 2 * count * count + 1;

    for (i = count-1; i >= 0; i--) {
        for (j = 0; j < count - i - 1; j++)
              cout<<" ";
        for (j = 0; j < 2 * i + 1; j++)
            cout << shape;
        cout<<endl;
    }

    for (i = 1; i < count; i++) {
        for (j = 0; j < count - i - 1; j++)
            cout<<" ";
        for (j = 0; j < 2 * i + 1; j++)
            cout << shape;
        cout<<endl;
    }

    cout << res;

    return 0;
}