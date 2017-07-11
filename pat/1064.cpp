#include <iostream>
#include <set>
using namespace std;

int getsum(int number)
{
    int s(0),b;
    while(number) {
        s+=number % 10;
        number/=10;
    }
    return s;
}
int main() {
    int n,num;
    int i;
   // int sum;

    set <int>ss;
    cin>>n;

    for(i=0;i<n;i++) {
        cin>>num;
        //sum = getsum(num);
        ss.insert(getsum(num));
    }
    cout<<ss.size()<<endl;

    for(auto m = ss.begin(); m != ss.end(); m++) {
        if(m != ss.end()) {
            cout << " ";
        }
        cout<< *m;
    }
    return 0;
}