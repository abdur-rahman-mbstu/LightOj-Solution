#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f,dp[10005];
long long fun(long long n)
{
    if(n==0) return dp[0]=a;
    if(n==1) return dp[1]=b;
    if(n==2) return dp[2]=c;
    if(n==3) return dp[3]=d;
    if(n==4) return dp[4]=e;
    if(n==5) return dp[5]=f;
    if(dp[n]==-1) dp[n]=((fun(n-1)%10000007)+(fun(n-2)%10000007)+(fun(n-3)%10000007)+(fun(n-4)%10000007)+(fun(n-5)%10000007)+(fun(n-6)%10000007))%10000007;
    return dp[n];
}
int main()
{
    long long n,T,t,i;
    cin>>T;
    for(t=1; t<=T; t++)
    {
        memset(dp,-1,sizeof(dp));
        cin>>a>>b>>c>>d>>e>>f>>n;
        fun(n);
        cout<<"Case "<<t<<": "<<dp[n]%10000007<<endl;
    }
    return 0;
}
