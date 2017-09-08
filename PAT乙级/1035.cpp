#include <iostream>
#include <string.h>
using namespace std;

void merge(int * a, int lo, int hi) {
    int mid, i, j, k;
    int aux[100];

    for (i = 0; i <= hi; i++) {
        aux[i] = a[i];
    }

    mid = (lo + hi) / 2;
    i = lo;
    j = mid + 1;

    for (k = lo; k <= hi; k++) {
        if (i > mid) {
            a[k] = aux[j++];
        } else if (j > hi) {
            a[k] = aux[i++];
        } else if (aux[j] < aux[i]) {
            a[k] = aux[j++];
        } else {
            a[k] = aux[i++];
        }
    }
}

bool comp(int * a, int * b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            return true;
    }
    return 0;
}

void printArray(int * a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i != n-1)
            cout<< " ";
        else
            cout << endl;
    }
}
int min(int x, int y) {
    if (x <= y)
        return x;
    else
        return y;
}

int main() {
    int a[100], b[100], c[100];
    int n, i, j,temp;
    int flag1 = 0;
    int flag2 = 0;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < n; i++) {
        cin >> b[i];
    }
    memcpy(c, a, n*4);

    // insertion sort
    for (i = 1; i < n; i++) {
        j = i;
        temp = c[j];
        while (temp < c[j-1] && j > 0) {
            c[j] = c[j-1];
            j--;
        }
        c[j] = temp;

        if (flag1 == 1) {
            if (comp(c, b, n) == 0)
                continue;
            cout<< "Insertion Sort" <<endl;
            printArray(c, n);
            return 0;
        }
        if (comp(c, b, n) == 0) {
            flag1 = 1;
        }
    }

    memcpy(c, a, n*4);

    // merge sort
    for (i = 1; i < n; i *= 2) {
        for (j = 0; j < n; j += 2 * i) {
            merge(c, j, min(j+2*i-1, n-1));
        }
        if (flag2 == 1) {
            cout << "Merge Sort" << endl;
            printArray(c, n);
            return 0;
        }
        if (comp(c, b, n) == 0)
            flag2 = 1;
    }
    return 0;
}