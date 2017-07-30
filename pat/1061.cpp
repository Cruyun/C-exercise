#include <iostream>
using namespace std;

int main() {
    int stu_num, test_num;
    int full[100],correct[100],answer[100][100];
    int score[100];
    int i, j;

    cin >> stu_num >> test_num;

    for (i = 0; i < test_num; i++) {
        cin >> full[i];
    }

    for (i = 0; i < test_num; i++) {
        cin >> correct[i];
    }

    for (i = 0; i < stu_num; i++) {
        for (j = 0; j < test_num; j++) {
            cin >> answer[i][j];
            if (answer[i][j] == correct[j])
                score[i] += full[j];
        }
    }

    for (i = 0; i < stu_num; i++) {
        cout << score[i] << endl;
    }

    return 0;
}