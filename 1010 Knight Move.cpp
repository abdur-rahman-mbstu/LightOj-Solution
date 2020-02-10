#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,j,p,q,T,t=1,ans,ok;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        if(n==1||m==1) ans = max(n,m);
        else if(n==2||m==2)
        {
            p = m*n;
            ans = (p/4);
            if(ans%2==0) ans = (ans/2)*4+(p%4);
            else ans = ((ans/2)+1)*4;
        }
        else
        {
            ans = (n*m)/2;
            ans+=(n*m)%2;
        }
        printf("Case %d: %d\n",t++,ans);
    }
}

