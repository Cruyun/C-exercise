#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int m, n, a, b, t;
    //cin >> m >> n >> a >> b >> t;
    scanf("%d%d%d%d%d", &m, &n, &a, &b, &t);
    int i, j;
    int input;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
//            cin >> input;
            scanf("%d", &input);
            if (input >= a && input <= b)
                input = t;
            if (j != 0)
                //cout << " ";
                printf(" ");
            //cout<<setfill('0') << setw(3) << input;
            printf("%03d", input);
        }
//        cout << endl;
        printf("\n");
    }
    return 0;
}

