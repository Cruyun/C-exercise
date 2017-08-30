#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int isPrime(int num) {
    int b,i;
    b = sqrt(num);
    for(i = b; i > 1;i--){
        if(num % i == 0)
            return 0;
    }
    return 1;
}


int main() {
    int n, i, num;
    int flag[9999]={0};
    cin >> n;

    for (i = 1; i <= n; i++) {
        cin >> num;
        flag[num] = i;// exist this number
    }

    int m, check[10000];

    cin >> m;
    for (i = 0; i < m; i++) {
        cin >> check[i];

        if (flag[check[i]] != 0) {
            if (flag[check[i]] != -1) {
                if (flag[check[i]] == 1) {
                    cout << setfill('0') << setw(4) << check[i] << ": Mystery Award" << endl;
                    flag[check[i]] = -1;
                }
                else if (isPrime(flag[check[i]])) {
                    cout << setfill('0') << setw(4) << check[i] << ": Minion"<< endl;
                    flag[check[i]] = -1;
                }
                else {
                    cout << setfill('0') << setw(4) << check[i] << ": Chocolate"<< endl;
                    flag[check[i]] = -1;
                }
            } else {
                cout << setfill('0') << setw(4) << check[i] << ": Checked" << endl;
                flag[check[i]] = -1;
            }
        } else
            cout << setfill('0') << setw(4) << check[i] << ": Are you kidding?"<< endl;

    }
    return 0;
}