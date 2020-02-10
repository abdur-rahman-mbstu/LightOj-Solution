#include<bits/stdc++.h>
using namespace std;
int n,m,dx,dy;
char s[25][25];
struct info
{
    int y,z;
    info(int a, int b)
    {
        y = a;
        z = b;
    }
};
queue<info>q;
int bfs(int x, int y)
{
    while(!q.empty()) q.pop();
    int i,j,u,v,vis[25][25]={0},dis[25][25],fx[]={0,0,1,-1},fy[]={1,-1,0,0},kk,ll,e=0;
    dis[x][y]=0;
    vis[x][y]=1;
    q.push(info(x,y));
    while(!q.empty())
    {
        info tp = q.front();
        q.pop();
        u = tp.y;
        v = tp.z;
        for(i=0;i<4;i++)
        {
            kk = u+fx[i];
            ll = v+fy[i];
            if(kk>=0&&kk<n&&ll>=0&&ll<m&& !vis[kk][ll]&& s[kk][ll]!='#'&&s[kk][ll]!='m')
            {
                vis[kk][ll]=1;
                q.push(info(kk,ll));
                dis[kk][ll]=dis[u][v]+1;
                if(kk==dx&&ll==dy)
                {
                    e=1;
                    break;
                    //cout<<"dis = "<<dis[kk][ll]<<endl;
                }
            }
        }
        if(e==1) break;
    }
    return dis[dx][dy];
}
int main()
{
    int i,j,T,t=1,ax,ay,bx,by,cx,cy,mx,pp;
    scanf("%d",&T);
    while(T--)
    {
        mx = 0;
        scanf("%d%d",&n,&m);
        getchar();
        for(i=0; i<n; i++)
        {
            scanf("%s",s[i]);
            for(j=0; j<m; j++)
            {
                if(s[i][j]=='a')
                {
                    ax = i;
                    ay = j;
                }
                if(s[i][j]=='b')
                {
                    bx = i;
                    by = j;
                }
                if(s[i][j]=='c')
                {
                    cx = i;
                    cy = j;
                }
                if(s[i][j]=='h')
                {
                    dx = i;
                    dy = j;
                }
            }
        }
        //cout<<ax<<" "<<ay<<endl<<bx<<" "<<by<<endl<<cx<<" "<<cy<<endl<<dx<<" "<<dy<<endl;
        pp = bfs(ax,ay);
        mx = max(mx,pp);
        pp = bfs(bx,by);
        mx = max(mx,pp);
        pp = bfs(cx,cy);
        mx = max(mx,pp);
        printf("Case %d: %d\n",t++,mx);
    }
    return 0;
}
