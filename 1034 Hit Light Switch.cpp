#include<bits/stdc++.h>
using namespace std;
vector<int>v[10002],lst;
bool vis[10002];
void dfs(int u)
{
    int i;
    vis[u]=1;
    for(i=0; i<v[u].size(); i++)
    {
        if(!vis[v[u][i]]) dfs(v[u][i]);
    }
    lst.push_back(u);
}
int main()
{
    int i,j,T,t=1,a,b,n,m;
    scanf("%d",&T);
    while(T--)
    {
        lst.clear();
        for(i=1; i<=10000; i++) v[i].clear();
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
        }
        memset(vis,0,sizeof(vis));
        for(i=1; i<=n; i++)
        {
            if(!vis[i]) dfs(i);
        }
        //for(i=0; i<lst.size(); i++) cout<<lst[i]<<" "; cout<<endl;
        int sz = lst.size(),cnt=0;
        memset(vis,0,sizeof(vis));
        for(i=sz-1; i>=0; i--)
        {
            if(!vis[lst[i]])
            {
                cnt++;
                dfs(lst[i]);
            }
        }
        printf("Case %d: %d\n",t++,cnt);
    }
}
