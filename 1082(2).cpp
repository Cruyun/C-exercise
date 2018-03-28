#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;

    int id, x, y;
    int max_id, min_id;
    int max_dis = -1;
    int min_dis = 99999;

    for (int i = 0; i < n; i++) {
        cin >> id >> x >> y;
        int distance = x * x + y * y;
        if (distance < min_dis) {
            min_id = id;
        }
        if (distance > max_dis) {
            max_id = id;
        }
        max_dis = max(max_dis, distance);
        min_dis = min(min_dis, distance);
    }

    printf("%04d %04d", min_id, max_id);
    return 0;
}
