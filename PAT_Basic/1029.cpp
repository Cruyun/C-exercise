#include <iostream>
#include <string>
using namespace std;

int main() {
    string real;
    string input;
    cin >> real >> input;

    bool check[256] = {false};
    int i;

    for (i = 0; i < input.length(); i++) {
        input[i] = toupper(input[i]);
        check[input[i]] = true;
    }
    for (i = 0; i < real.length(); i++) {
        real[i] = toupper(real[i]);
        if (check[real[i]] == false)
            cout << real[i];
        check[real[i]] = true;
    }
    return 0;
}