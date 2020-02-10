#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct info
{
    ll u,v,w;
}in[12005];
bool cmp(info a, info b)
{
    return a.w<b.w;
}
ll par[12005];
ll fnd(ll r)
{
    if(par[r]==r) return r;
    else return par[r]=fnd(par[r]);
}
ll kruskl(ll n, ll m)
{
    ll cnt=0,i,sm=0,a,b;
    for(i=0;i<=n;i++) par[i]=i;
    for(i=0;i<m;i++)
    {
         a = fnd(in[i].u);
         b = fnd(in[i].v);
         if(a!=b)
         {
             par[a] = b;
             cnt++;
             sm+=in[i].w;
             if(cnt==n) break;
         }
    }
    return sm;
}
ll krul(ll n, ll m)
{
    ll cnt=0,i,sm=0,a,b;
    for(i=0;i<=n;i++) par[i]=i;
    for(i=m-1;i>=0;i--)
    {
         a = fnd(in[i].u);
         b = fnd(in[i].v);
         if(a!=b)
         {
             par[a] = b;
             cnt++;
             sm+=in[i].w;
             if(cnt==n) break;
         }
    }
    return sm;
}
int main()
{
    ll T,n,p,q,w,t=1,i;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(i=0;;i++)
        {
            scanf("%lld%lld%lld",&in[i].u,&in[i].v,&in[i].w);
            if(in[i].u==0&&in[i].v==0&&in[i].w==0) break;
        }
        sort(in,in+i,cmp);
        p = kruskl(n,i);
        q = krul(n,i);
        //cout<<p<<" "<<q<<endl;
        q+=p;
        if(q&1) printf("Case %lld: %lld/2\n",t++,q);
        else printf("Case %lld: %lld\n",t++,q/2);
    }
    return 0;
}
