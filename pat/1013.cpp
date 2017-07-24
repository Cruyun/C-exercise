#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b;
    int count(0), i, t, j;

    cin >> a >> b;
    for (i = 2; count <= b; i++) {
        t = 0;
        for (j = 2; j <= sqrt(i); j++)
            if (i % j == 0)
                ++t;
        if (t == 0)
            ++count;
        if (count >= a && count <= b && t == 0) {
            cout << i;
            if ((count - a) % 10 == 9)
                cout << endl;
            else if (count != b)
                cout << " ";

        }
    }
    cout << endl;

    return 0;
}