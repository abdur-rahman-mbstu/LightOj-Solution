#include<bits/stdc++.h>
using namespace std;
int m,a[1002],dis[1002];
vector<int>v[1002];
bool chk[1002],vis[1002];
bool bfs(int sc)
{
    int i,u,vv,z=0;
    queue<int>qq;
    qq.push(sc);
    dis[sc]=0;
    vis[sc]=1;
    while(!qq.empty())
    {
        u = qq.front();
        qq.pop();
        for(i=0;i<v[u].size();i++)
        {
            vv = v[u][i]+u;
            if(vv<=m&& !vis[vv])
            {
                vis[vv]=1;
                dis[vv]=dis[u]+1;
                qq.push(vv);
            }
            if(vv==m)
            {
                z=1;
                break;
            }
        }
        if(z) break;
    }
}
void seive()
{
    int i,j,k=0,p,q;
    for(i=3;i<=1000;i+=2) chk[i]=1;
    for(i=3;i*i<=1000;i+=2)
    {
        if(chk[i]==1)
        {
            for(j=i*i;j<=1000;j+=i+i) chk[j]=0;
        }
    }
    a[k++]=2;
    for(i=3;i<=1000;i+=2)
    {
        if(chk[i]==1) a[k++]=i;
    }
    //for(i=0;i<10;i++) cout<<a[i]<<" "; cout<<endl;
    for(i=4;i<=1000;i++)
    {
        if(chk[i]==1) continue;
        p = i;
        for(j=0;a[j]*a[j]<=p;j++)
        {
            q=0;
            while(p%a[j]==0)
            {
                q=a[j];
                p/=a[j];
            }
            if(q) v[i].push_back(a[j]);
            if(p==1) break;
        }
        if(p!=1) v[i].push_back(p);
    }
    /*for(i=1;i<=20;i++)
    {
        cout<<i<<"->  ";
        for(j=0;j<v[i].size();j++) cout<<v[i][j]<<" "; cout<<endl;
    }*/
}
int main()
{
    seive();
    int i,j,T,t=1,ans,n;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        dis[m]=-1;
        ans=bfs(n);
        printf("Case %d: %d\n",t++,dis[m]);
    }
    return 0;
}
