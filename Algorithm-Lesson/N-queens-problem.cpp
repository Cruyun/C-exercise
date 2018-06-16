#include <iostream>
using namespace std;

void Queen();
int Place(int k);


const int N = 4;
int x[N] = {-1};

int main() {
    Queen();
    return 0;
}

int Place(int k)
{
    for (int i = 0; i < k; i++) {
        if (x[i] == x[k] || abs(i - k) == abs(x[i] - x[k])) {
            return 1;
        }
    }
    return 0;
}

void Queen()
{
    int k = 0;
    while (k >= 0) {
        x[k]++;
        while (x[k] < N && (Place(k) == 1)) {
            x[k]++;
        }
        if (x[k] < N && (k == N - 1)) {
            for (int i = 0; i < N; i++) {
                cout << x[i] + 1 << " ";
            }
            cout << endl;
            return;
        }
        if (x[k] < N && k < N - 1) {
            k = k + 1;
        } else {
            x[k--] = -1;
        }
    }

    cout << "无解" << endl;
}