#include <iostream>
#include <cstdio>
using namespace std;


int main() {
    int n;
    cin >> n;

    string name, max_name, min_name;
    int year, month, day;
    int count(0);
    int max_year(0), max_month(0), max_day(0);
    int min_year(9999), min_month(9999), min_day(9999);

    for (int i = 0; i < n; i++) {
        cin >> name;
        scanf("%d/%d/%d", &year, &month, &day);
        if ((year < 2014 || (year == 2014 && month < 9) || (year == 2014 && month == 9 && day <= 6)) &&
            (year >1814 || (year == 1814 && month > 9) || (year == 1814 && month == 9 && day >= 6))) {
            count++;
            if (year > max_year || (year == max_year && month > max_month) ||
                (year == max_year && month == max_month && day > max_day)) {
                max_day = day;
                max_month = month;
                max_year = year;
                max_name = name;
            }
            if (year < min_year || (year == min_year && month < min_month) ||
                (year == min_year && month == min_month && day < min_day)) {
                min_day = day;
                min_month = month;
                min_year = year;
                min_name = name;
            }
        }
    }

    cout << count;
    if (count) cout << " " << min_name << " " << max_name;
    return 0;
}