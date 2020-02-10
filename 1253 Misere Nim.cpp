#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,k,i,j,sm,T,t=1,cnt,a[110];
    scanf("%lld",&T);
    while(T--)
    {
        cnt=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            if(a[i]==1) cnt++;
        }
        printf("Case %lld: ",t++);
        if(cnt==n)
        {
            if(cnt&1) printf("Bob\n");
            else printf("Alice\n");
            continue;
        }
        sm = a[0];
        for(i=1;i<n;i++) sm^=a[i];
        if(sm>0) printf("Alice\n");
        else printf("Bob\n");
    }
}
