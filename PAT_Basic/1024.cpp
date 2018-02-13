#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    string input;
    cin >> input;

    if (input[0] == '-') {
        cout << "-";
    }

    int e_pos = input.find('E');
    int exp = atoi((input.substr(e_pos+1)).c_str());
    string basic = input.substr(1,e_pos-1);

    if (exp < 0) {
        basic.erase(1, 1);
        basic.insert(0,(-exp)-1,'0');
        cout << "0." << basic << endl;
    } else {
        if (exp < (basic.length() - 2)) {
            basic.erase(1, 1);
            basic.insert(exp+1, 1, '.');
            cout << basic << endl;
        } else {
            int n = exp - basic.length() + 2;
            basic.insert(basic.length(), n, '0');
            basic.erase(1,1);
            cout << basic << endl;
        }
    }

    return 0;
}