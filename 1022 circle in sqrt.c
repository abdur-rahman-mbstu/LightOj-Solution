#include<stdio.h>
#include<math.h>
#define PI (2*acos(0.0))
main()
{
    int i,t;
    double r,area;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lf",&r);
        area=4*r*r-PI*r*r;
        printf("Case %d: %.2lf\n",i,area);
    }
    return 0;
}
