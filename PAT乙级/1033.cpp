#include <iostream>
#include <string>
using namespace std;

int main() {
    string wrong;
    string input;

    getline(cin, wrong); //cin >> wrong;
    getline(cin, input); //cin >> input;

    int i;
    int flag = 0;
    bool check[128]={false};
    int len1 = wrong.length();
    int len2 = input.length();

    if (len1 == 0) {
        cout << input;
        return 0;
    }

    for (i = 0; i < len1; i++) {
        check[wrong[i]] = true;
        if (wrong[i] <= 'Z' && wrong[i] >= 'A')
            check[wrong[i] + 32] = true;

    }
    for (i = 0; i < len2; i++) {
        if (check[input[i]] != true) {
            if ((check['+'] == true) && (input[i] >= 'A' && input[i] <= 'Z'))
                continue;
            else {
                cout << input[i];
                flag = 1;
            }
        }
    }
    if (!flag)
    cout << endl;
    return 0;
}