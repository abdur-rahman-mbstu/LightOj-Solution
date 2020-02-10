#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,T,t,p,q,ans;
    cin>>T;
    for(t=1; t<=T; t++)
    {
        cin>>n>>m;
        ans=0;
        if(m==n)
        {
            if(n%3==0||n%3==2) ans=1;
        }
        else if((n%3==0&&m%3==0)||(n%3==2&&m%3==2)||(n%3==2&&m%3==0))
        {
            p=m-n;
            q=p/3;
            ans=p-q+1;
        }
        else
        {
            p=m-n;
            q=p/3;
            ans=p-q;
        }
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}

