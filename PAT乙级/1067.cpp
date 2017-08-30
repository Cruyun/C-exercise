#include <iostream>
using namespace std;

int main() {
    string correct;
    int n;
    cin >> correct >> n;

    string quit = "#";

    int wrong = 0;
    getchar();
    while(1){
        string input;
        getline(cin, input);
        if (quit == input)
            break;

        if (correct == input && wrong <= n) {
            cout << "Welcome in" << endl;
            break;
        }else if (correct != input && wrong <= n) {
            cout << "Wrong password: " << input << endl;
            wrong++;
            if (wrong == n) {
                cout << "Account locked" << endl;
                break;
            }
        }
    }

    return 0;
}