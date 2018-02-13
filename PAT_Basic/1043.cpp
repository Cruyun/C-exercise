#include <iostream>

using namespace std;

int main() {
    char input[6]={0};
    string pat;
    cin>>pat;

    for(int i = 0; i< pat.size() ; i++) {
        if (pat[i]=='P')
            input[0]++;
        else if(pat[i]=='A')
            input[1]++;
        else if(pat[i]=='T')
            input[2]++;
        else if(pat[i]=='e')
            input[3]++;
        else if(pat[i]=='s')
            input[4]++;
        else if(pat[i]=='t')
            input[5]++;
    }
    while (input[0] + input[1] + input[2] + input[3] + input[4] + input[5] != 0){
        if (input[0] != 0) {
            cout << 'P';
            input[0]--;
        }
        if (input[1] != 0) {
            cout << 'A';
            input[1]--;
        }
        if (input[2] != 0) {
            cout << 'T';
            input[2]--;
        }
        if (input[3] != 0) {
            cout << 'e';
            input[3]--;
        }
        if (input[4] != 0) {
            cout << 's';
            input[4]--;
        }
        if (input[5] != 0) {
            cout << 't';
            input[5]--;
        }
    }

    return 0;
}