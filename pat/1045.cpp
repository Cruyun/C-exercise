#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//主元的条件：左边的元素都比他小，右边的元素都比他大

bool cmp(int a, int b) {
    return a < b;
}
int main() {
    int n;
    cin >> n;

    int i;
    int k(0);
    int input[100000], b[100000];

    for (i = 0; i < n; i++) {
        cin >> input[i];
        b[i] = input[i];
    }
    sort(input, input+n);

    int max = 0;
    int result[10000];

    for (i = 0; i < n; i++) {
        if (input[i]== b[i] && b[i] > max) {
            result[k++] = b[i];
        }
        if (b[i] > max) {
            max = b[i];
        }
    }

    cout << k << endl;

    for (i = 0; i < k; i++) {
        if (i != k-1)
            cout << result[i] << " ";
        else
            cout << result[i];
    }
    cout << endl;
    return 0;
}