#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,r,c,r1,r2,c1,c2,T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        printf("Case %d: ",t++);
        r = abs(r1-r2);
        c = abs(c1-c2);
        if(r==c) printf("1\n");
        else if((r%2==0&&c%2==0)||(r%2==1&&c%2==1)) printf("2\n");
        else printf("impossible\n");
    }
}
