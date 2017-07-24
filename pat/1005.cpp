#include <iostream>
using namespace std;

int main() {
    int n, i, j, k, t;
    int input[100]={0};
    int copy[100]={0};
    int result[100]={0};

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> input[i];
        copy[i] = input[i];
    }

    for (i = 0; i < n; i++) {
        if (copy[i] != 0) {
            while (input[i] != 1) {
                if (input[i] % 2 == 0)
                    input[i] /= 2;
                else
                    input[i] = (3 * input[i] + 1) / 2;
                for (j = 0; j < n; j++)
                    if (copy[j] == input[i])
                        copy[j] = 0;
            }
        }
    }


    k = 0;
    for (i = 0; i < n; i++)
        if (copy[i] != 0)
            result[k++] = copy[i];

    //冒泡排序
    for (i = 1; i < k; i++){
        for (j = 0; j < k -1; j++){
            if (result[j] < result[j+1]){
                t = result[j];
                result[j] = result[j+1];
                result[j+1] = t;
            }
        }
    }

    for (i = 0; i < k - 1; i++){
        cout << result[i] << " ";
    }
    cout << result[k-1];

    return 0;
}