#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, d;
    double e, data;
    cin >> n >> e >> d;

    int i, j, k;
    int count, maybe = 0, must = 0;
    double result1, result2;

    for (i = 0; i < n; i++) {
        cin >> k;
        count = 0;
        for (j = 0; j < k; j++) {
            cin >> data;
            if (data < e)
                count++;
        }
        if (count > (k / 2)) {
            if (k > d)
                must++;
            else
                maybe++;
        }
    }

    result1 = (double)maybe / n * 100;
    result2 = (double)must / n * 100;

    cout << fixed << setprecision(1) << result1 << "% ";
    cout << fixed << setprecision(1) << result2 << "%";

    return 0;
}