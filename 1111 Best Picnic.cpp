#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
int cnt[1002];
bool vis[1002];
vector<int>v[1002];
void dfs(int p)
{
    cnt[p]++;
    vis[p]=1;
    int i,u;
    for(i=0;i<v[p].size();i++)
    {
        u = v[p][i];
        if(vis[u]==0) dfs(u);
    }
}
int main()
{
    int n,m,k,i,j,p,T,t=1,per[1002],a,b,c;
    sc("%d",&T);
    while(T--)
    {
        sc("%d%d%d",&k,&n,&m);
        for(i=0; i<k; i++) sc("%d",&per[i]);
        for(i=0; i<m; i++)
        {
            sc("%d%d",&a,&b);
            v[a].push_back(b);
        }
        c=0;
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<k;i++)
        {
            memset(vis,0,sizeof(vis));
            dfs(per[i]);
        }
        for(i=1;i<=n;i++)
        {
            if(cnt[i]>=k) c++;
        }
        pr("Case %d: %d\n",t++,c);
        for(i=1;i<=n;i++) v[i].clear();
    }
    return 0;
}
