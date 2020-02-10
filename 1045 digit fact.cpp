#include<stdio.h>
#include<math.h>
double ans[1000005],k;
int main()
{
    int i,n,b,T;
    ans[0]=0;
    for(i=1; i<=1000000; i++)
        ans[i]=ans[i-1]+log10(i);
    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        scanf("%d%d",&n,&b);
        k=floor(ans[n]/log10(b*1.0)+1);
        printf("Case %d: %.0lf\n",t,k);
    }
    return 0;
}
