#include<bits/stdc++.h>
using namespace std;
bool vis[501][501];
int n,m,p,q,cnt,value[502][502],*dp[502][502];
char s[502][502];
void dfs(int x, int y)
{
    if(x<0||x==n||y<0||y==m||vis[x][y]||s[x][y]=='#') return;
    vis[x][y]=1;
    dp[x][y] = &value[p][q];
    if(s[x][y]=='C') value[p][q]++;
    dfs(x,y+1);
    dfs(x,y-1);
    dfs(x+1,y);
    dfs(x-1,y);
    return;
}
int main()
{
    int i,j,T,t=1,x,y,qry;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d",&n,&m,&qry);
        getchar();
        for(i=0; i<n; i++) scanf("%s",s[i]);
        printf("Case %d:\n",t++);
        while(qry--)
        {
            cnt=0;
            scanf("%d%d",&p,&q);
            p--;
            q--;
            if(!vis[p][q])
            {
                value[p][q]=0;
                dfs(p,q);
            }
            printf("%d\n",*dp[p][q]);
        }
    }
    return 0;
}
