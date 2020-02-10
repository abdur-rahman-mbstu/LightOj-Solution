#include<bits/stdc++.h>
#define mx 2300
using namespace std;
bool check[mx+5];
long long a[mx+10],k=0,b[10000];
double cp[5000005];

void prime()
{
    long long i,j;
    for(i=3; i<=mx; i+=2)
        check[i]=true;
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
    {
        if(check[i]==true)
            a[k++]=i;
    }
    long long n,m,bb,dd;
    double p,sm;
    for(dd=2; dd<=5000000; dd++)
    {
        n=m=dd;
        j=0;
        for(i=0; a[i]*a[i]<=n; i++)
        {
            if(n%a[i]==0)
            {
                while(n%a[i]==0)
                    n/=a[i];
                b[j++]=a[i];
            }
        }
        double d=1;
        if(n!=1)
            b[j++]=n;
        for(i=0; i<j; i++)
            d*=(b[i]-1.0)/b[i];
        p=m*d;
        p=p*p;
        if(m==1) p=0;
        cp[dd]=p;
    }
}
int main()
{
    prime();
    unsigned long long i,r,v,T,t;
    double sm;
    scanf("%llu",&T);
    for(t=1; t<=T; t++)
    {
        sm=0;
        scanf("%llu%llu",&r,&v);
        if(r>v) swap(r,v);
        for(i=r; i<=v; i++)
            sm+=cp[i];
        printf("Case %llu: %.0lf\n",t,sm);
    }
    return 0;
}
