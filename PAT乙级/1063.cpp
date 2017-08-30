#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n(0);
    int a[10000],b[10000];
    double result[10000];
    double max;

    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        result[i]=sqrt(a[i]*a[i]+b[i]*b[i]);
    }
    max=result[0];
    for(int i=1;i<n;i++) {
        if(max<result[i])
            max=result[i];
    }

    cout<<fixed<<setprecision(2)<<max;
    return 0;
}