#include<bits/stdc++.h>
using namespace std;
#define mx 5000001
typedef unsigned long long ll;
ll phi[mx+5];
int main()
{
    ll i,j;
    for(i=2; i<mx; i++)
    {
        if(!phi[i]==1)
        {
            phi[i]=i-1;
            for(j=2*i; j<mx; j+=i)
            {
                if(!phi[j]==1) phi[j]=j;
                phi[j]-=(phi[j]/i);
            }
        }
    }
    for(i=2; i<=mx; i++)
    {
        phi[i]*=phi[i];
        phi[i]+=phi[i-1];
    }
    ll n,m,T,t;
    scanf("%llu",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%llu%llu",&n,&m);
        if(n>m) swap(n,m);
        printf("Case %llu: %llu\n",t,phi[m]-phi[n-1]);
    }
    return 0;
}
