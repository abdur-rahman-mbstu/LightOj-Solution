#include<bits/stdc++.h>
using namespace std;
struct info
{
    int u,v,w;
} in[52];
bool cmp(info a, info b)
{
    return a.w<b.w;
}
int par[52];
int fnd(int x)
{
    if(par[x]==x) return x;
    else return par[x]=fnd(par[x]);
}
int main()
{
    int n,m,i,j,p,q,sm,T,t=1,a,k,kk,sm1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        k=0;
        sm=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%d",&a);
                sm+=a;
                if(a>0&&i!=j)
                {
                    in[k].u=i;
                    in[k].v=j;
                    in[k].w=a;
                    k++;
                }
            }
        }
        for(i=0;i<=50;i++) par[i]=i;
        //for(i=0;i<k;i++) cout<<in[i].u<<" "<<in[i].v<<" "<<in[i].w<<endl;
        sort(in,in+k,cmp);
        kk=0;
        sm1=0;
        int cnt=0;
        for(i=0;i<k;i++)
        {
            p = fnd(in[i].u);
            q = fnd(in[i].v);
            if(p!=q)
            {
                par[p]=q;
                sm1+=in[i].w;
                cnt++;
                if(cnt==n-1)
                {
                    kk=1;
                    break;
                }
            }
        }
        if(n==1) kk=1;
        printf("Case %d: ",t++);
        if(kk) printf("%d\n",sm-sm1);
        else printf("-1\n");
    }
}

