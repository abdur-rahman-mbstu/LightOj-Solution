#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[20],n,m,ans;
ll lcm(ll a, ll b)
{
    return (a*b)/__gcd(a,b);
}
ll fun(ll idx, ll lc, ll tak)
{
    ll p,q,i;
    if(idx==m) return 0;
    for(i=idx; i<m; i++)
    {
        p=lcm(a[i],lc);
        if((tak+1)&1) ans+=(n/p);
        else ans-=(n/p);
        fun(i+1,p,tak+1);
    }
    return ans;
}
int main()
{
    ll i,j,p,T,t=1;
    scanf("%lld",&T);
    while(T--)
    {
        ans=0;
        scanf("%lld%lld",&n,&m);
        for(i=0; i<m; i++) scanf("%lld",&a[i]);
        p=fun(0,1,0);
        printf("Case %lld: %lld\n",t++,n-p);
    }
    return 0;
}
