// 部分正确。应该要考虑是同一个人的情况，这个写法太复杂了

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

struct Players {
    string id;
    int x;
    int y;
    int distance;
};

int cmp(struct Players a, struct Players b) {
    return a.distance < b.distance ? a.distance : b.distance;
}

int main() {
    int n;
    cin >> n;
    
    vector<Players> player(n);

    for (int i = 0; i < n; i++) {
        cin >> player[i].id >> player[i].x >> player[i].y;

        player[i].distance = abs(player[i].x) * abs(player[i].x) + abs(player[i].y) * abs(player[i].y);
    }

    sort(player.begin(), player.end(), cmp);
    cout << player[0].id << " " << player[n-1].id;

    return 0;
}

