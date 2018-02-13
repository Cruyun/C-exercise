// 有坑。。还以为只要另外考虑b比较长的情况就可以了，没想到a比较长的时候要把b用0补全。最后倒序输出。还有就是要注意把字符转换成int
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

    for (temp = 0; temp < len_b || temp < len_a ;temp++) {
        // b 比 a 长
        if (pos_a >= 0 && pos_b >= 0) {
            if (temp % 2 == 0) {
                result[temp] = ((a[pos_a] - '0') + (b[pos_b] - '0')) % 13;
            } else {
                result[temp] = (b[pos_b] - '0') - (a[pos_a] - '0');
            }
        }
        else if (pos_a < 0 && pos_b >= 0){
            result[temp] = b[pos_b]-'0';
        }
        // a 比 b 长
        else if (pos_b < 0 && pos_a >= 0) {
            if (temp % 2 == 0) {
                result[temp] = (a[pos_a] - '0') % 13;
            } else {
                result[temp] = - (a[pos_a] - '0');
            }
        }
        pos_a--;
        pos_b--;
    }

    int i = temp;
    for (i--; i >= 0; i--) {
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