#include<stdio.h>
main()
{
    int a,b,c,t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        c=a+b;
        printf("Case %d: %d\n",i,c);
    }
}
