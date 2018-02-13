#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(char a, char b) {
    return a > b;
}
int main() {
    string N;
    cin >> N;
    if (N.size() < 4) {
        for(int i = N.size(); i < 4; i++){
            N.push_back('0');
        }
    }

    do {
        string temp1 = N;
        string temp2 = N;
        sort(temp1.begin(),temp1.end(),cmp);
        sort(temp2.begin(),temp2.end());
        int result = stoi(temp1) - stoi(temp2);
        N = to_string(result);
        N.insert(0, 4 - N.length(), '0');
        cout << temp1 << " - " << temp2 << " = " << N << endl;
    } while(N != "6174" && N != "0000");

    return 0;
}