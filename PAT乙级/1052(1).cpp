// 第二个测试点出现段错误是因为还需要判断序号的合法性，等于0也是不行的
// 这是膜大佬的vector版本，用数组也可以

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<string>> m;

    for (int j = 0; j < 3; j++) {
        string s;
        getline(cin, s);
        int k=0, l=0;
        vector<string> s1;
        while (k < s.length()) {
            if (s[k] == '[') {
                while (l++ < s.length()) {
                    if (s[l] == ']') {
                        s1.push_back(s.substr(k+1, l-k-1));
                        break;
                    }
                }
            }
            k++;
        }
        m.push_back(s1);
    }
    int n;
    cin >> n;

    int h1,h2,e1,e2,mo;

    for (int i = 0; i < n; i++) {
        cin >> h1 >> e1 >> mo >> e2 >> h2;
        if (h1 <= m[0].size() && h2 <= m[0].size() && mo <= m[2].size() && e1 <= m[1].size() && e2 <= m[1].size() && h1 >0 && h2 >0 && mo >0 && e1 > 0 && e2 >0) {
            cout << m[0][h1-1] << "(" << m[1][e1-1] << m[2][mo-1] << m[1][e2-1] << ")" << m[0][h2-1] << endl;
        } else {
            cout << "Are you kidding me? @\\/@" << endl;
        }
    }
    return 0;
}