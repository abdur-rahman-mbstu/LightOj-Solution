#include<bits/stdc++.h>
using namespace std;
vector<int>v[102];
bool vis[102];
int sdis[102],ddis[102];
queue<int>q;
void bfs(int sc)
{
    int vv,i,j,fr;
    for(i=0;i<=100;i++) vis[i]=0;
    sdis[sc]=0;
    q.push(sc);
    vis[sc]=1;
    while(!q.empty())
    {
        fr = q.front();
        q.pop();
        for(i=0;i<v[fr].size();i++)
        {
            vv = v[fr][i];
            if(!vis[vv])
            {
                vis[vv]=1;
                sdis[vv] = sdis[fr]+1;
                q.push(vv);
            }
        }
    }
}
int main()
{
    int n,m,i,a,b,j,T,t=1,src,des,p,mx;
    scanf("%d",&T);
    while(T--)
    {
        mx=0;
        for(i=0;i<=100;i++) v[i].clear();
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        scanf("%d%d",&src,&des);
        bfs(src);
        for(i=0;i<n;i++) ddis[i]=sdis[i];
        //for(i=0;i<n;i++) cout<<ddis[i]<<" "; cout<<endl;
        bfs(des);
        //for(i=0;i<n;i++) cout<<sdis[i]<<" "; cout<<endl;
        for(i=0;i<n;i++)
        {
            p = ddis[i]+sdis[i];
            mx = max(mx,p);
        }
        printf("Case %d: %d\n",t++,mx);
    }
    return 0;
}
