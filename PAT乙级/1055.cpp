#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct person {
    string name;
    int height;
};
int cmp(struct person a, struct person b) {
    return a.height == b.height ? a.name < b.name : a.height > b.height;
}
int main() {
    int n, k, m;
    int i;
    cin >> n >> k;
    vector<person> per(n);
    for (i = 0; i < n; i++) {
        cin >> per[i].name;
        cin >> per[i].height;
    }

    sort(per.begin(),per.end(), cmp);

    int t = 0, row = k;
    while (row) {
        if (row == k)
            m = n - n / k * (k - 1);
        else
            m = n / k;
        vector<string> s(m);
        s[m / 2] = per[t].name;

        int j = m / 2 - 1;

        for (i = t + 1; i < t + m; i+=2)
            s[j--] = per[i].name;
        j = m / 2 + 1;
        for (i = t + 2; i < t + m; i+=2) {
            s[j++] = per[i].name;
        }
        cout << s[0];
        for (i = 1; i < m; i++) {
            cout << " " << s[i];
        }
        cout << endl;
        t = t + m;
        row--;
    }


    return 0;
}