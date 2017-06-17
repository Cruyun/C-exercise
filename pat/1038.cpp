#include<iostream>
using namespace std;
int main()
{
   int n, m;
   int temp, temp1;
   cin>>n;
   int hash[101] = {0};
   for(int i=0; i<n; i++) {
       cin>>temp;
       hash[temp]++;
   }
    cin>>m;
    for(int i=0; i<m; i++) {
        cin>>temp1;
        cout<<hash[temp1];
        if(i==m-1)
            cout<<endl;
        else
            cout<<" ";
    }
    return 0;
}

