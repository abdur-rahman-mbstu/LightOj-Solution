#include<stdio.h>
#include<math.h>
main()
{
    double a,b,c,d,h,s,area,e,ar,p;
    int t,i;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        if(a<c)
        {
            p=c;
            c=a;
            a=p;
        }
        e=a-c;
        s=(b+d+e)/2;
        ar=sqrt(s*(s-b)*(s-d)*(s-e));
        h=(2*ar)/e;
        area=.5*((a+c)*h);
        printf("Case %d: %.7lf\n",i,area);
        area=0;
    }
    return 0;
}
