#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sc scanf
#define pr printf
ll a[202][202],dp[202][202],n;
ll fun(ll x, ll y)
{
    //cout<<x<<" "<<y<<endl;
    if(dp[x][y]!=-1) return dp[x][y];
    ll p=0,q=0,pp=0;
    if(x>2*n) return 0;
    if(y==0) return 0;
    if(a[x][y]==0) return 0;
    p = a[x][y]+fun(x+1,y);
    if(x<n) q = a[x][y]+fun(x+1,y+1);
    else pp = a[x][y]+fun(x+1,y-1);
    return dp[x][y] = max(p,max(q,pp));
}
int main()
{
    ll i,j,T,t=1;
    sc("%lld",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(dp,-1,sizeof(dp));
        sc("%lld",&n);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=i; j++) sc("%lld",&a[i][j]);
        }
        for(i=n+1; i<2*n; i++)
        {
            for(j=1; j<=2*n-i; j++) sc("%lld",&a[i][j]);
        }
        pr("Case %lld: %lld\n",t++,fun(1,1));
    }
    return 0;
}
