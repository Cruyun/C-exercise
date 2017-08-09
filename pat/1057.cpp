#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int i, result(0), count1(0), count0(0);

    getline(cin, input);
    for (i = 0; i < input.length(); ++i) {
        if (input[i] <= 'z' && input[i] >= 'a')
            result += input[i] - 96;
        else if (input[i] <='Z' && input[i] >= 'A')
            result += input[i] - 64;
    }
    while (result != 0) {
        if (result % 2 == 0) {
            count0++;
        } else
            count1++;
        result /= 2;
    }
    cout << count0 << " "<< count1;
    return 0;
}