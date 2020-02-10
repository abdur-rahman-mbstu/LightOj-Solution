#include<bits/stdc++.h>
using namespace std;
main()
{
    long long i,n,t,k;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        if(__builtin_popcount(n)&1)
            printf("Case %lld: odd\n",i);
        else
            printf("Case %lld: even\n",i);
    }
    return 0;
}
