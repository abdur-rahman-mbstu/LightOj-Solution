#include<stdio.h>
main()
{
    long long t,i,n,count,rem;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        count=0;
        scanf("%lld",&n);
        while(n!=0)
        {
            rem=n%2;
            n/=2;
            if(rem==1)
                count++;
        }
        if(count%2==0)
            printf("Case %lld: even\n",i);
        else
            printf("Case %lld: odd\n",i);
    }
    return 0;
}
