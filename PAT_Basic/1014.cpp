#include <iostream>
#include <string>
using namespace std;

int main() {
    char s[4][61];
    string day[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int i;
    bool week = true;

    for (i = 0; i < 4; i++) {
        cin >> s[i];
    }

    for (i = 0; i < 60; i++) {
        if (week && s[0][i] == s[1][i] && s[0][i] >= 'A' && s[1][i] <= 'G') {
            week = false;
            cout << day[s[0][i] - 'A'] << " ";
            continue;
        }
        if (!week && s[0][i] == s[1][i] && ((s[0][i] >= 'A' && s[1][i] <= 'N') || isdigit(s[0][i]))) {
            if (isupper(s[0][i]))
                cout << s[0][i] - 'A' + 10<< ":";
            else
                cout << "0" << s[0][i] - '0' << ":";
            break;
        }
    }

    for (i = 0; i < 60; i++) {
        if (isalpha(s[2][i]) && s[2][i] == s[3][i]) {
            cout << i / 10 << i % 10 << endl;
            break;
        }
    }
    return 0;
}