#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long T,t,i,n,m,ans;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>n>>m;
        ans=(n/2)*m;
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}
