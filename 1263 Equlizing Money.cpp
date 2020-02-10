#include<bits/stdc++.h>
using namespace std;
vector<int>v[1002];
int a[1002],cnt,mny;
bool vis[1002];
void dfs(int pos)
{
    if(vis[pos]) return;
    vis[pos]=1;
    int i,kk,pp;
    for(i=0; i<v[pos].size(); i++)
    {
        pp = v[pos][i];
        if(!vis[pp])
        {
            cnt++;
            mny+=a[pp];
            dfs(pp);
        }
    }
}
int main()
{
    int T,t=1,i;
    map<int,int>mp;
    scanf("%d",&T);
    while(T--)
    {
        mp.clear();
        int x,y,sm=0,p,j=0,n,m;
        scanf("%d%d",&n,&m);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sm+=a[i];
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        printf("Case %d: ",t++);
        if(sm%n!=0)
        {
            printf("No\n");
            continue;
        }
        p = sm/n;
        memset(vis,0,sizeof(vis));
        for(i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                cnt=1;
                mny=a[i];
                dfs(i);
                //cout<<cnt<<" "<<mny<<endl;
                if(cnt*p!=mny)
                {
                    j=1;
                    break;
                }
            }
        }
        if(!j) printf("Yes\n");
        else printf("No\n");
        for(i=1; i<=n; i++) v[i].clear();
    }
    return 0;
}

