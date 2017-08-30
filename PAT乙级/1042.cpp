#include <iostream>
#include <string>
using namespace std;

int main() {
    char input[1001];
    int count[128]={0};
    int i;

    gets(input);
        for (i = 0; input[i] != '\0'; i++) {
            if (input[i] >= 'A' && input[i] <= 'Z')
                count[input[i] + 32]++;
            else if (input[i] >= 'a' && input[i] <= 'z')
                count[input[i]]++;
        }


    int max = 0;
    int temp = 0;
    for (i = 0; i < 128; i++) {
        if (max < count[i]) {
            max = count[i];
            temp = i;
        }
    }
    cout << (char)temp << " " << max << endl;

    return 0;
}