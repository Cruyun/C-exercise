#include <iostream>
#include <cctype>

using namespace std;

int main() {
    int n;

    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i) {

        bool flag1 = false; // contains alpha
        bool flag2 = false; // contains number
        bool flag3 = false; // error char
        string input;
        getline(cin, input);

        if (input.length() < 6) {
            cout << "Your password is tai duan le." << endl;
            continue;
        } else {
            for (int j = 0; j < input.length(); ++j) {
                if (isalpha(input[j])) {
                    flag1 = true;
                }
                if (isdigit(input[j])) {
                    flag2 = true;
                }
                if (!isalpha(input[j]) && !isdigit(input[j]) && input[j] != '.') {
                    flag3 = true;
                }
            }

            if (flag3) {
                cout << "Your password is tai luan le." << endl;
            } else if (!flag1) {
                cout << "Your password needs zi mu." << endl;
            } else if (!flag2) {
                cout << "Your password needs shu zi." << endl;
            } else {
                cout << "Your password is wan mei." << endl;
            }
        }
    }
    return 0;
}