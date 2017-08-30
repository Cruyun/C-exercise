#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void number(string s);
void str(string s);

string lows[13]={"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string highs[13]={"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main() {
    int n;
    string s;
    cin >> n;
    getchar(); // 没有这句是答案错误。。很懵逼

    for (int i = 0; i < n; i++) {
        getline(cin, s);

        if (isdigit(s[0])) {
            number(s);
        } else
            str(s);
        cout << endl;
    }
    return 0;
}

void number(string s) {
    int len = s.length();
    int num = 0;
    int a;
    int b;


    for (int i = 0; i < len; i++) {
        num = num * 10 + (s[i] - '0');
    }
    if (num == 0) {
        cout << "tret";
        return;
    }

    a = num % 13;
    b = num / 13;
    cout << highs[b];

    if (b != 0 && a != 0) {
        cout << " " << lows[a];
        return;
    } else if (a != 0){
        cout << lows[a];
        return;
    }

}

void str(string s) {
    int len = s.length();
    int num = 0;
    string a,b;

    if (len == 4) {
        cout << 0;
        return;
    } else if (len == 3) {
        for (int i = 1; i <= 12; i++) {
            if (s == lows[i]) {
                cout << i;
                return;
            }
            if (s == highs[i]) {
                cout << i * 13;
                return;
            }
        }
    } else if (len > 3){
        a = s.substr(0,3);
        b = s.substr(4,3);
        for (int i = 1; i <= 12; i++) {
            if (a == highs[i]) {
                num += i * 13;
            }
            if (b == lows[i]) {
                num += i;
            }
        }
        cout << num;
    }
}