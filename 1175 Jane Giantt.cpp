#include<bits/stdc++.h>
using namespace std;
char s[202][203],ch;
int jan[202][203],r,c,fx[]= {0,0,1,-1},fy[]= {1,-1,0,0},dis[202][202],vis[202][202];
pair<int, int>p;
queue<pair<int,int> >q;
void bfs(int x, int y)
{
    int xx,yy;
    memset(vis,0,sizeof(vis));
    jan[x][y]=1;
    vis[x][y]=1;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            xx = p.first+fx[i];
            yy = p.second+fy[i];
            if(xx>=0&&xx<r&&yy>=0&&yy<c&&s[xx][yy]!='#'&&vis[xx][yy]==0)
            {
                jan[xx][yy]=jan[p.first][p.second]+1;
                q.push(make_pair(xx,yy));
                vis[xx][yy]=1;
            }
        }
    }
}
void bfs1(int x, int y)
{
    int xx,yy;
    memset(vis,0,sizeof(vis));
    dis[x][y]=1;
    vis[x][y]=1;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            xx = p.first+fx[i];
            yy = p.second+fy[i];
            //cout<<xx<<" "<<yy<<" "<<dis[xx][yy]<<endl;
            if(xx>=0&&xx<r&&yy>=0&&yy<c&&s[xx][yy]!='#'&&vis[xx][yy]==0&&(dis[p.first][p.second]+1)<dis[xx][yy])
            {
                dis[xx][yy]=dis[p.first][p.second]+1;
                q.push(make_pair(xx,yy));
                vis[xx][yy]=1;
            }
        }
    }
}
int main()
{
    int n,m,i,j,T,t=1,fx,fy,jx,jy;
    scanf("%d",&T);
    while(T--)
    {
        int mn=978;
        memset(jan,0,sizeof(jan));
        for(i=0;i<201;i++)
        {
            for(j=0;j<201;j++) dis[i][j]=978;
        }
        scanf("%d%d",&r,&c);
        getchar();
        for(i=0; i<r; i++)
        {
            scanf("%s",s[i]);
            for(j=0; j<c; j++)
            {
                if(s[i][j]=='J')
                {
                    jx=i;
                    jy=j;
                }
            }
        }
        //for(i=0; i<r; i++) {printf("%s",s[i]); cout<<endl;}
        //cout<<jx<<" "<<jy<<"    "<<fx<<" " <<fy<<endl;
        bfs(jx,jy);
        /*for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++) cout<<dis[i][j]<<" "; cout<<endl;
        }*/
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(s[i][j]=='F') bfs1(i,j);
            }
        }
        /*for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++) cout<<jan[i][j]<<" "; cout<<endl;
        }
        cout<<endl<<"FIRE"<<endl;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++) cout<<dis[i][j]<<" "; cout<<endl;
        }*/

        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if((i==0||j==0||i==r-1||j==c-1)&&(jan[i][j]<dis[i][j]&&jan[i][j]>0))
                {
                    mn = min(mn,jan[i][j]);
                    //cout<<i<<" "<<j<<" "<<fir[i][j]<<" "<<dis[i][j]<<endl;
                }
            }
        }
        if(mn!=978) printf("Case %d: %d\n",t++,mn);
        else printf("Case %d: IMPOSSIBLE\n",t++);
    }
}

