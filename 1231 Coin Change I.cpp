#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int coin[55],num[55],n,k,dp[52][1004];
int fun(int pos, int amt)
{
    int p=0;
    //cout<<pos<<" "<<amt<<endl;
    if(dp[pos][amt]!=-1) return dp[pos][amt];
    if(pos==n)
    {
        if(amt==k) return 1;
        else return 0;
    }
    if(amt==k) return 1;
    if(amt>k) return 0;
    for(int i=1; i<=num[pos];i++)
    {
        if(amt+coin[pos]*i<=k) p=(p+fun(pos+1,amt+coin[pos]*i))%mod;
    }
    p=(p+fun(pos+1,amt))%mod;
    return dp[pos][amt] = p;
}
int main()
{
    int i,j,T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++) scanf("%d",&coin[i]);
        for(i=0;i<n;i++) scanf("%d",&num[i]);
        printf("Case %d: %d\n",t++,fun(0,0));
    }
    return 0;
}
