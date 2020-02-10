#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a[5],T,t;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]) cout<<"Case "<<t<<": yes"<<endl;
        else cout<<"Case "<<t<<": no"<<endl;
    }
    return 0;
}
