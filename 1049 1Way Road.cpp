#include<bits/stdc++.h>
using namespace std;
vector<int>v[102];
int cst[102][102],cost,cost1,q;
bool vis[102];
void dfs(int p)
{
    int i,u;
    if(vis[p]) return;
    vis[p]=1;
    for(i=0; i<v[p].size(); i++)
    {
        u = v[p][i];
        if(!vis[u])
        {
            cost+=cst[p][u];
            cost1+=cst[u][p];
            q=u;
            dfs(u);
        }
    }
}
int main()
{
    int t=1,T,i,j,n,m,x,y,w;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        memset(cst,0,sizeof(cst));
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            cst[x][y]=0;
            cst[y][x]=w;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        cost=0;
        cost1=0;
        dfs(1);
        cost+=cst[q][1];
        cost1+=cst[1][q];
        //cout<<cost<<" "<<cost1<<endl;
        printf("Case %d: %d\n",t++,min(cost,cost1));
        for(i=1; i<=n; i++) v[i].clear();
    }
}
