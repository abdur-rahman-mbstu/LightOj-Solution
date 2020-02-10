#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,n,x1,x2,y1,y2,a,b,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d",&n);
        printf("Case %d:\n",i);
        while(n--)
        {
            scanf("%d%d",&a,&b);
            if(a>x1&&a<x2&&b>y1&&b<y2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
