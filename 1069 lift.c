#include<stdio.h>
main()
{
    long long x1,x2,t,s,i;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld%lld",&x1,&x2);
        if(x2>x1)
        s=19+(x2-x1)*4+x1*4;
        else
            s=19+(x1-x2)*4+x1*4;
        printf("Case %lld: %lld\n",i,s);
    }
    return 0;
}
