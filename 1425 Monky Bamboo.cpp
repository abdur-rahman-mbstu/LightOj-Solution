#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
    int t,T,i,n,p,a[100005];
    cin>>T;
    for(t=1; t<=T; t++)
    {
        int mx=-423;
        v.clear();
        a[0]=0;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>a[i];
            p=abs(a[i]-a[i-1]);
            if(p>mx) mx=p;
            v.push_back(p);
        }
        cout<<"Case "<<t<<": ";
        //sort(v.begin(),v.end(),greater<int>());
        //if(v[0]==v[1]) cout<<v[0]+1<<endl;
            int ans=mx;
            for(i=0; i<v.size(); i++)
            {
                if(v[i]==ans) ans--;
                else if(v[i]>ans) {ans=-1;break;}
            }
            if(ans<0) cout<<mx+1<<endl;
            else cout<<mx<<endl;
    }
    return 0;
}
