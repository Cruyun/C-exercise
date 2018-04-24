#include <iostream>

using namespace std;
int index_BF(string &S, string &T,int pos);
int index_KMP(string &S, string &T, int pos);

int main() {
    int pos;
    string S, T;

    cout << "input the parent string: ";
    cin >> S;
    cout << "input the child string: ";
    cin >> T;
    cout << "input the started position:(the first index is 0) ";
    cin >> pos;

    int BF_result = index_BF(S, T, pos);
    int KMP_result = index_KMP(S, T, pos);
    if (BF_result != -1) {
        cout << "BF: they match in the " << BF_result<< " letter in the first time(the first index is 0)" << endl;
    } else {
        cout << "no match" << endl;
    }

    if (KMP_result != -1) {
        cout << "KMP: they match in the " << KMP_result<< " letter in the first time(the first index is 0)" << endl;
    } else {
        cout << "no match" << endl;
    }
    return 0;
}

int index_BF(string &S, string &T,int pos)
{
    int i = pos;
    int j = 0;
    int S_len = S.size();
    int T_len = T.size();

    while(i < S_len && j < T_len) {
        if(S[i] == T[j]) {
            i++;
            j++;
        }
        else {
            i = i-j+1;
            j = 0;
        }
    }

    if(j >= T_len)
        return i - T_len;
    else
        return -1;
}

int index_KMP(string &S, string &T, int pos) {
    int i = pos;
    int j = 0;
    int S_len = S.size();
    int T_len = T.size();
    int k = -1;
    int next[T_len];

    next[0] = -1;
    while (j < T_len) {
        if (k == -1 || T[j] == T[k]) {
            j++;
            k++;
            if (T[j] != T[k]) {
                next[j] = k;
            } else {
                next[j] = next[k];
            }
        } else {
            k = next[k];
        }
    }
    j = 0;

    while(i < S_len && j < T_len) {
        if(j == -1 || S[i] == T[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }

    if(j >= T_len)
        return i - T_len;
    else
        return -1;
}