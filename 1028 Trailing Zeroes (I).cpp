#include<bits/stdc++.h>
#define mx 1000105
using namespace std;
bool check[mx+5];
long long a[mx+5],k=0;
void prime()
{
    long i,j;
    for(i=3; i<=mx; i+=2) check[i]=true;
    for(i=3; i*i<=mx; i+=2)
    {
        if(check[i]==true)
        {
            for(j=i*i; j<=mx; j+=i+i)
                check[j]=false;
        }
    }
    a[k++]=2;
    for(i=3; i<=mx; i+=2)
        if(check[i]==true) a[k++]=i;
}
int main()
{
    prime();
    vector<long long>b;
    long long n,i,T,t,cnt,ans;
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        b.clear();
        scanf("%lld",&n);
        for(i=0; a[i]*a[i]<=n; i++)
        {
            cnt=0;
            while(n%a[i]==0)
            {
                cnt++;
                n/=a[i];
            }
            b.push_back(cnt);
        }
        ans=1;
        if(n!=1) b.push_back(1);
        for(i=0; i<b.size(); i++)
            ans*=(b[i]+1);
        printf("Case %lld: %lld\n",t,ans-1);
    }
    return 0;
}
