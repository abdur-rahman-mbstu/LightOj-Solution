#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>g[1005],cst[1005];
struct node
{
    int u,w;
    node(int p, int q)
    {
        u=p;
        w=q;
    }
    bool operator<(const node&p) const
    {
        return p.w<w;
    }
};
priority_queue<node>pq;
int dis[1005];
void djk(int sc, int tar)
{
    int kk=0,i,u,v;
    for(i=0;i<1004;i++) dis[i]=100000000;
    pq.push(node(sc,0));
    dis[sc]=0;
    while(!pq.empty())
    {
        node tp = pq.top(); pq.pop();
        u = tp.u;
        for(i=0; i<g[u].size(); i++)
        {
            v=g[u][i];
            if(dis[u]+cst[u][i]<dis[v])
            {
                dis[v]=dis[u]+cst[u][i];
                pq.push(node(v,dis[v]));
            }
        }
    }
    if(dis[tar]==100000000) cout<<"Impossible"<<endl;
    else cout<<dis[tar]<<endl;
}
int main()
{
    int T,p,q,i,j,wt,t=1;
    cin>>T;
    while(T--)
    {
        for(i=0; i<1002; i++)
        {
            g[i].clear();
            cst[i].clear();
        }
        cin>>n>>m;
        while(m--)
        {
            cin>>p>>q>>wt;
            g[p].push_back(q);
            g[q].push_back(p);
            cst[p].push_back(wt);
            cst[q].push_back(wt);
        }
        cout<<"Case "<<t++<<": ";
        djk(1,n);
    }
    return 0;
}
