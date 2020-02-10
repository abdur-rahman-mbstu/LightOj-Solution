#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,k,i,j,sm,T,t=1,cnt,a[110],p;
    scanf("%lld",&T);
    while(T--)
    {
        cnt=0;
        scanf("%lld%lld",&n,&m);
        for(i=0; i<n; i++)
        {
            cnt=0;
            for(j=0; j<m; j++)
            {
                scanf("%lld",&p);
                cnt+=p;
            }
            a[i]=cnt;
        }
        printf("Case %lld: ",t++);
        sm = a[0];
        for(i=1; i<n; i++) sm^=a[i];
        if(sm>0) printf("Alice\n");
        else printf("Bob\n");
    }
}

