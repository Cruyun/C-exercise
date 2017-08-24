// 唯一的坑在于ID不足5位要补0
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int n,m;
    int a,b;
    int alone[10000]; // 落单
    int attend[10000]; //参加人数
    int check[100000]={0}; //id

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        check[a] = b;
        check[b] = a;
    }
    cin >> m;
    for (int j = 0; j < m; j++) {
        cin >> attend[j];
    }
    int * p;

    int a_len=0;
    for (int k = 0; k < m; k++) {
        p = find(attend, attend+m,check[attend[k]]);
        if (p == attend+m) {
            alone[a_len] = attend[k];
            a_len++;
        }
    }

    cout << a_len << endl;

    sort(alone,alone+a_len);
    for (int l = 0; l < a_len; l++) {
        if (l != a_len-1)
            printf("%05d ",alone[l]);
        else
            printf("%05d",alone[l]);
    }

    return 0;
}