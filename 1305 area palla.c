#include<stdio.h>
main()
{
    long long a1,a2,b1,b2,c1,c2,d1,d2,area;
    int t,i;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&a1,&a2,&b1,&b2,&c1,&c2);
        if(a1<=1000&&a1>=-1000&&a2>=-1000&&a2<=1000&&b1<=1000&&b1>=-1000&&c1<=1000&&c1>=-1000&&c2>=-1000&&c2<=1000&&b2<=1000&&b2>=-1000)
        {
            d1=a1+c1-b1;
            d2=a2+c2-b2;
            area=(b1*d2-d1*b2)+(a1*b2-b1*a2)+(d1*a2-a1*d2);
            if(area<0)
                area=-area;
            printf("Case %d: %lld %lld %lld\n",i,d1,d2,area);
        }
    }
    return 0;
}
