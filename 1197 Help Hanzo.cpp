#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 46350
ll pr[mx],k=0;
bool chk[mx];
void seive()
{
    int i,j;
    for(i=3; i<=mx; i+=2) chk[i]=1;
    for(i=3; i*i<=mx; i+=2)
    {
        if(chk[i])
        {
            for(j=i*i; j<=mx; j+=i+i) chk[j]=0;
        }
    }
    pr[k++]=2;
    for(i=3; i<=mx; i+=2) if(chk[i]) pr[k++]=i;
    //cout<<k<<" "<<pr[k-1]<<endl;
}
ll segSiv(ll lw, ll hg)
{
    bool mark[100002];
    memset(mark,1,sizeof(mark));
    ll i,st,cnt=0,j;
    for(i=0; i<k; i++)
    {
        if(pr[i]>hg) break;
        st = floor((double)lw/pr[i])*pr[i];
        if(st<lw) st+=pr[i];
        if(st==pr[i]) st+=pr[i];
        //cout<<pr[i]<<" "<<st<<endl;
        for(j=st; j<=hg; j+=pr[i]) mark[j-lw]=0;
    }
    for(i=lw; i<=hg; i++)
    {
        if(mark[i-lw])
        {
            cnt++;
            //cout<<i<<" ";
        }
    }
    return cnt;
}
int main()
{
    seive();
    ll i,j,T,t=1,n,m;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
        if(n==1&&m==1)
        {
           printf("Case %lld: 0\n",t++);
           continue;
        }
        if(n==1) n=2;
        printf("Case %lld: %lld\n",t++,segSiv(n,m));
    }
}
