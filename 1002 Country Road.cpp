#include<bits/stdc++.h>
using namespace std;
vector<int>v[505],cost[505];
struct info
{
    int u,w;
    info(int a, int b)
    {
        u = a; w = b;
    }
    bool operator<(const info&p) const
    {
        return p.w<w;
    }
};
priority_queue<info>pq;
void djk(int src, int n)
{
    int d[505],i,j,u,vv;
    pq.push(info(src,0));
    for(i=0;i<n;i++) d[i]=555555;
    d[src]=0;
    while(!pq.empty())
    {
        info tp = pq.top(); pq.pop();
        u = tp.u;
        for(i=0;i<v[u].size();i++)
        {
            vv = v[u][i];
            if(d[vv]>max(d[u],cost[u][i]))
            {
                d[vv]=max(d[u],cost[u][i]);
                pq.push(info(vv,d[vv]));
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(d[i]==555555) printf("Impossible\n");
        else cout<<d[i]<<endl;
    }
}
int main()
{
    int T,t=1,i,j,p,q,n,m,src,cst;
    scanf("%d",&T);
    while(T--)
    {
        for(i=0;i<=501;i++)
        {
            v[i].clear();
            cost[i].clear();
        }
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%d%d%d",&p,&q,&cst);
            v[p].push_back(q);
            v[q].push_back(p);
            cost[p].push_back(cst);
            cost[q].push_back(cst);
        }
        scanf("%d",&src);
        printf("Case %d:\n",t++);
        djk(src,n);
    }
    return 0;
}
