#include<stdio.h>
main()
{
    long long a,b,c,i,t,d,p,h,n,m;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a>c)
        {
            p=c;
            c=a;
            a=p;
        }
        if(b>c)
        {
            p=c;
            c=b;
            b=p;
        }
        if(a>=1&&c<=40000)
        {
            h=a*a;
            n=b*b;
            m=c*c;
            d=h+n;
        }
        if(d==m)
            printf("Case %d: yes\n",i);
        else
            printf("Case %d: no\n",i);
    }
    return 0;
}
