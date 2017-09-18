// 部分正确，在输入为6174的时候也应该进行运算
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void recursion(string num);

int main() {
    string N;
    cin >> N;
    recursion(N);
    return 0;
}

void recursion(string num) {
    int i;

    if (num.size() < 4) {
        for(i = num.size(); i < 4; i++){
            num.push_back('0');
        }
    }
    sort(num.begin(),num.end());
    string temp1 = num;
    reverse(num.begin(),num.end());
    string temp2 = num;

    cout << temp2 << ' ' << '-';
    cout << ' ' << temp1 << ' ' << '=' << ' ';

    if(temp1 == temp2){
        cout << "0000" << endl;
        return;
    }
    int val1 = stoi(temp1);
    int val2 = stoi(temp2);
    int val = val2 - val1;
    string str = to_string(val);
    cout << str << endl;
    if(str == "6174")
        return;
    else
        return recursion(str);
}
