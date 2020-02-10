#include<bits/stdc++.h>
using namespace std;
long long pwr(long long n, long long p)
{
    long long m=1;
    for(int i=1;i<=p;i++) m*=n;
    return m;
}
int main()
{
    long long n,m,i,j,p,q,T,t=1,a[50],b[50],ans,ok;
    scanf("%lld",&T);
    while(T--)
    {
        q=0;
        scanf("%lld",&n);
        while(n!=0)
        {
            p =n%2;
            a[q++]=p;
            n/=2;
        }
        p=0;
        ok=0;
        for(i=0;i<q;i++)
        {
            if(p==1&&a[i]==0)
            {
                ok=1;
                break;
            }
            if(a[i]==1) p=1;
        }
        if(ok==0) a[q++]=0;
        for(i=q-1; i>=0; i--) b[q-i-1]=a[i];
        //for(i=0;i<q;i++) cout<<b[i]; cout<<endl;
        next_permutation(b,b+q);
        //for(i=0;i<q;i++) cout<<b[i]; cout<<endl;
        p=0;
        ans=0;
        for(i=q-1;i>=0;i--)
        {
            ans+=(b[i]*pwr(2,q-i-1));
            p++;
        }
        printf("Case %lld: %lld\n",t++,ans);
    }
}
