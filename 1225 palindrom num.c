#include<stdio.h>
main()
{
    long int t,n,i,a,c,b;
    scanf("%ld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%ld",&a);
        b=a;
        n=0;
        while(a!=0)
        {
            c=a%10;
            a=a/10;
            n=n*10+c;
      }
      if(n==b)
        printf("Case %ld: Yes\n",i);
      else
        printf("Case %ld: No\n",i);
    }
    return 0;
}
