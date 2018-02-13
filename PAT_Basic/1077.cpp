#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, full;
    cin >> n >> full;


    for (int i = 0; i < n; i++) {
        double teacher, sum;
        int ava;
        int legal_stu = 0;
        sum = 0.0;

        cin >> teacher;

        vector<double> students;
        for (int j = 0; j < n - 1; j++) {
            double x;
            cin >> x;

            if (x >= 0 && x <= full) {
                students.push_back(x);
                sum += x;
            }
        }

        sort(students.begin(), students.end());
        legal_stu = students.size();

        double stu_score = (sum - students[0] - students[legal_stu - 1]) / (legal_stu - 2);
        ava = int((teacher + stu_score) / 2 + 0.5);
        cout << ava << endl;
    }
    return 0;
}