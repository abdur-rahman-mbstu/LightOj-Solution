#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    long long p,q,r,i,t,n,count,j,sum,a[100],c,k;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        count=0;
        sum=0;
        c=0;
        scanf("%lld%lld%lld",&n,&p,&q);
        for(j=0; j<n; j++)
            scanf("%lld",&a[j]);
        sort(a,a+n);
        for(j=0; j<n; j++)
        {
            c++;
            sum=sum+a[j];
            if(c<=p&&sum<=q)
                count++;
        }
        printf("Case %lld: %lld\n",i,count);
    }
    return 0;
}
