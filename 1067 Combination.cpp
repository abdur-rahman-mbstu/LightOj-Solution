//modular multiplicative inverse a*a^(m-2)=1(mod m) or a^-1=a^(m-2) (mod m)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000003
ll fact[1000002],modInv[1000002];
long long square(long long n)
{
    return n*n;
}
ll bigmod(ll b, ll p)
{
    if(p==0) return 1;
    else if(p&1) return (b*(bigmod(b,p-1)))%mod;
    else return square(bigmod(b,p/2))%mod;
}
int main()
{
    ll t=1,T,i,j,n,r,ans,pp;
    fact[0]=1;
    for(i=1;i<=1000000;i++) fact[i] = (fact[i-1]*i)%mod;
    //for(i=1;i<=10;i++) cout<<fact[i]<<" "; cout<<endl;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&r);
        ans = (fact[r]*fact[n-r])%mod;
        pp = bigmod(ans,mod-2);
        //cout<<ans<<" "<<pp<<endl;
        ans = (fact[n]*pp)%mod;
        printf("Case %lld: %lld\n",t++,ans);
    }
}
