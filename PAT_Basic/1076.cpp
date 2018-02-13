#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    char choice, answer;
    char sign;
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> choice >> sign >> answer;
            if (answer == 'T') {
                cout << choice - 64;
            }
        }
    }
    return 0;
}