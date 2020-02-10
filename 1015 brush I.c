#include<stdio.h>
main()
{
    int t,a,sum=0,i,j,n;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d",&n);
        sum=0;
        for(j=1; j<=n; j++)
        {
            scanf("%d",&a);
            if(a>0)
                sum=sum+a;
        }
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
