#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
int p_result(void);

int main() {
    int PA, PB, P;
    PA = p_result();
    PB = p_result();
    P = PA + PB;
    cout << P;
}

int p_result()
{
    char str[11] = { '\0' };
    char d;
    int p=0;
    int count = 0, i = 0, j = 0;

    cin >> str >> d;

    for (int i = 0; i < 11; i++)
    {
        if (str[i] == d) count++;

    }
    for (int j = 0; j < count; j++) {
        p += (d - 48) * pow((double)10, j);
    }

    return p;
}
