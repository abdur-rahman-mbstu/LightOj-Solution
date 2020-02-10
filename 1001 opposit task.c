#include<stdio.h>
main()
{
    int t,n,a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        a=n%10;
        b=n/10;
        c=b*10;
        if(c>10)
        {
            d=c/2;
            c=d;
            a=a+d;
        }
        printf("%d %d\n",a,c);
    }
    return 0;
}
