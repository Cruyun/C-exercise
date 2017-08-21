#include <iostream>
using namespace std;

int main() {
    string a,b;
    cin >> a >> b;

    int len_a = a.length();
    int len_b = b.length();
    int result[100] = {0};
    int pos_a = len_a -1;
    int pos_b = len_b - 1;
    int temp;

    for (temp = 0; temp < len_b; temp++) {
        if (pos_a >= 0) {
            if (temp % 2 == 0) {
                result[temp] = ((a[pos_a] - '0') + (b[pos_b] - '0')) % 13;
            } else {
                result[temp] = (b[pos_b] - '0') - (a[pos_a] - '0');
            }
        }
        else {
            result[temp] = b[pos_b]-'0';
        }
        pos_a--;
        pos_b--;
    }

    for (int i = len_b -1; i >= 0; i--) {
        if (result[i] == 10)
            cout << 'J';
        else if (result[i] == 11)
            cout << 'Q';
        else if (result[i] == 12)
            cout << 'K';
        else if (result[i] < 0)
            cout << result[i] + 10;
        else
            cout << result[i];
    }

    return 0;
}