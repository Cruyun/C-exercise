#include <iostream>
using namespace std;

int main() {
    int count = 0;
    char m;
    int p = 0;
    int pa = 0;
    int pat = 0;

    while (cin >> m && m != ' ' && m != '\n') {
        if (m == 'P') {
            p++;
        }
        else if (m == 'A') {
            pa += p;
            pa  =  pa % 1000000007;
        }
        else {
            pat += pa;
            pat = pat % 1000000007;
        }
    }
    cout << pat << endl;
    return 0;
}