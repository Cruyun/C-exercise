#include <iostream>
#include <map>
using namespace std;

int main() {
    int total, space, first;
    cin >> total >> space >> first;

    string input;
    map<string, int> list;
    int flag = 0;
    for (int i = 1; i <= total; i++) {
        cin >> input;
        if (list[input] == 1)
            first++;
        if (i == first && list[input] == 0) {
            cout << input << endl;
            list[input] = 1;
            flag = 1;
            first += space;
        }
    }

    if (flag == 0)
        cout << "Keep going...";
    return 0;
}