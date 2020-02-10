#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int fx[]= {1,-1,0,0},fy[]= {0,0,1,-1},h,w,cell[25][25],cnt;
queue<pair<int,int> >q;
void bfs(int scx, int scy)
{
    int vis[25][25],tx,ty,i;
    memset(vis,0,sizeof(vis));
    q.push(pii(scx,scy));
    vis[scx][scy]=1;
    while(!q.empty())
    {
        pii tp = q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            tx=tp.first+fx[i];
            ty=tp.second+fy[i];
            if(tx>0&&tx<=h&&ty>0&&ty<=w&&vis[tx][ty]==0&&cell[tx][ty]!=-1)
            {
                vis[tx][ty]=1;
                cnt++;
                q.push(pii(tx,ty));
            }
        }
    }
}
int main()
{
    //freopen("1012in.txt","r",stdin);
    //freopen("1012out.txt","w",stdout);
    int i,j,scx,scy,T,t=1;
    char ch;
    scanf("%d",&T);
    while(T--)
    {
        cnt=1;
        memset(cell,0,sizeof(cell));
        scanf("%d%d",&w,&h);
        getchar();
        for(i=1; i<=h; i++)
        {
            for(j=1; j<=w; j++)
            {
                if(j!=w) scanf("%c",&ch);
                else {scanf("%c",&ch);getchar();}
                if(ch=='@')
                {
                    scx=i;
                    scy=j;
                }
                else if(ch=='#') cell[i][j]=-1;
            }
        }
        bfs(scx,scy);
        printf("Case %d: %d\n",t++,cnt);
    }
    return 0;
}
