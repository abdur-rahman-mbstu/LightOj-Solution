#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,T,t,p,q,a,b,ans,x,y;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>n>>m;
        p=n%3;
        q=m%3;
        x=n-p;
        y=m-q;
        if(p==2) a=x-(x/3)+1;
        else a=x-(x/3);
        if(q==2) b=y-(y/3)+1;
        else b=y-(y/3);
        ans=b-a;
        if(p!=1) ans++;
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}
