//习题3_1
#include <iostream>
using namespace std;

int main()
{
    int num[]={0};
    int a[]={0};
    int b[]={0};
    int i,j(0),k(0),a_num(0),b_num(0),t;

    for (i=0;i<10;i++){
        cin >> num[i];
        if (num[i] % 2 == 1) {
            a[j] = num[i];
            j++;
        } else {
            b[k] = num[i];
            k++;
        }
    }
    a_num=j;
    b_num=k;

    for(i=1; i<a_num;i++) {
        for (j=0; j<a_num-1; j++) {
            if (a[j] > a[j+1]) {
                t = a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }

    for(i=0; i < a_num; i++)
        cout << a[i];
    
    for(i=1; i<b_num;i++) {
        for (j=0; j<b_num-1; j++) {
            if (b[j] > b[j+1]) {
                t = b[j];
                b[j]=b[j+1];
                b[j+1]=t;
            }
        }
    }

    for(i=0;i<b_num;i++)
        cout << b[i];

    return 0;
}

