#include <iostream>
using namespace std;

int main() {
    int n,i;
    double input[100001];
    double sum =0.0;

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> input[i];
        sum += input[i] *(n - i + 1) * i;
    }

    printf("%.2f",sum);
    return 0;
}