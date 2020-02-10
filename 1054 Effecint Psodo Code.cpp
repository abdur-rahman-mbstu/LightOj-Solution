#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mx 46400
ll pr[3002];
bool chk[mx+2];
void seive()
{
    int i,j,k=0;
    for(i=3; i<=mx; i+=2) chk[i]=1;
    for(i=3; i*i<=mx; i+=2)
    {
        if(chk[i])
        {
            for(j=i*i; j<=mx; j+=i+i) chk[j]=0;
        }
    }
    pr[k++]=2;
    for(i=3; i<=mx; i+=2)
    {
        if(chk[i]) pr[k++]=i;
    }
    //cout<<k<<" "<<pr[k-1]<<endl;
}
long long square(long long n)
{
    return n*n;
}
long long bigmod(long long b,long long pw)
{
    //cout<<pw<<endl;
    if(pw==0) return 1;
    else if(pw%2==0) return square(bigmod(b,pw/2))%mod;
    else return ((b % mod)*bigmod(b,pw-1))%mod;
}
int main()
{
    seive();
    ll i,j,n,m,T,t=1,p,up,lw,cnt;
    scanf("%lld",&T);
    while(T--)
    {
        up=1;
        lw=1;
        scanf("%lld%lld",&n,&p);
        for(i=0; pr[i]*pr[i]<=n; i++)
        {
            cnt=0;
            while(n%pr[i]==0)
            {
                cnt++;
                n/=pr[i];
            }
            //cout<<pr[i]<<" "<<cnt<<endl;
            up = (up*(bigmod(pr[i],(cnt*p+1))-1))%mod;
            if(up<0) up = (up+mod)%mod;
            lw= (lw*(pr[i]-1))%mod;
            if(lw<0) lw = (lw+mod)%mod;
        }
        if(n!=1)
        {
            up=(up*(bigmod(n,p+1)-1))%mod;
            if(up<0) up = (up+mod)%mod;
            lw=(lw*(n-1))%mod;
            if(lw<0) lw = (lw+mod)%mod;
        }
        lw = bigmod(lw,mod-2);
        if(lw<0) lw = (lw+mod)%mod;
        //cout<<up<<" " <<lw<<endl;
        ll ans = (up*lw+mod)%mod;
        printf("Case %lld: %lld\n",t++,ans);
    }
    return 0;
}
