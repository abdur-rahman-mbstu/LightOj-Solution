#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define ll long long
int n,m,d,a[205];
ll dp[202][22][12];
ll fun(int pos, int sm, int cnt)
{
    ll p=0,q=0;
    if(sm<0) sm+=d;
    if(dp[pos][sm][cnt]!=-1) return dp[pos][sm][cnt];
    if(pos==n)
    {
        if(sm==0&&cnt==m) return 1;
        return 0;
    }
    if(cnt==m)
    {
        if(sm==0) return 1;
        return 0;
    }
    p = fun(pos+1,(sm+a[pos])%d,cnt+1);
    q = fun(pos+1,sm,cnt);
    return dp[pos][sm][cnt] = p+q;
}
int main()
{
    int T,t=1,i,j,qry;
    sc("%d",&T);
    while(T--)
    {
        sc("%d%d",&n,&qry);
        pr("Case %d:\n",t++);
        for(i=0; i<n; i++) sc("%d",&a[i]);
        while(qry--)
        {
            memset(dp,-1,sizeof(dp));
            sc("%d%d",&d,&m);
            printf("%lld\n",fun(0,0,0));
        }
    }
    return 0;
}
