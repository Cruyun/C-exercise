#include <iostream>
#include <string>
using namespace std;

void compressString(string s) {
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        count++;
        if (s[i] != s[i + 1]) {
            if (count != 1) {
                cout << count << s[i];
            } else {
                cout << s[i];
            }
            count = 0;
        }
    }
}

void decompressString(string s) {
    for (int i = 0; i < s.length(); i++) {
        int temp = 0;
        while (isdigit(s[i])) {
            temp = temp * 10 + (s[i++] - '0');
        }
        for (int j = 0; j < temp; ++j) {
            cout << s[i];
        }
        if (temp == 0) {
            cout << s[i];
        }
    }
}

int main() {
    char a;
    cin >> a;
    if (a == 'C') {
        string s1;
        getchar();
        getline(cin, s1);
        compressString(s1);
    } else if (a == 'D') {
        string s2;
        getchar();
        getline(cin, s2);
        decompressString(s2);
    }
    return 0;
}