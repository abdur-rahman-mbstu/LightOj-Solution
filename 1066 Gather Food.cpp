#include<bits/stdc++.h>
using namespace std;
#define pr printf
#define mk make_pair
int n;
string s[15];
int a,b;
char sc,tar;
int bfs(int xx, int yy)
{
    int u,v,i,j,dis[12][12],fx[]= {0,0,1,-1},fy[]= {1,-1,0,0},vis[12][12]= {0};
    queue<pair<int,int> >q;
    pair<int,int>p;
    q.push(mk(xx,yy));
    dis[xx][yy]=0;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            u = p.first+fx[i];
            v = p.second+fy[i];
            if(u>=0&&u<n&&v<n&&v>=0&&(s[u][v]=='.'||s[u][v]==tar)&&vis[u][v]==0)
            {
                dis[u][v] = dis[p.first][p.second]+1;
                vis[u][v]=1;
                if(s[u][v]==tar)
                {
                    a = u;
                    b = v;
                    s[xx][yy]='.';
                    return dis[u][v];
                }
                q.push(mk(u,v));
            }
        }
    }
    return -1;
}
int main()
{
    int T,t=1,i,j,pp,qq;
    scanf("%d",&T);
    while(T--)
    {
        qq=0;
        int cnt=0;
        scanf("%d",&n);
        for(i=0; i<n; i++) cin>>s[i];
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(s[i][j]=='A')
                {
                    a = i;
                    b = j;
                }
                if(isalpha(s[i][j])) cnt++;
            }
        }
        pr("Case %d: ",t++);
        if(cnt==1)
        {
            pr("0\n");
            continue;
        }
        tar = 'A';
        //cout<<a<<" "<<b<<endl;
        for(i=1; i<cnt; i++)
        {
            sc = tar;
            tar = sc+1;
            pp = bfs(a,b);
            //cout<<pp<<" "<<sc<<" "<<tar<< " "<<a<<" "<<b<<endl;
            if(pp==-1)
            {
                qq=0;
                break;
            }
            else qq+=pp;

        }
        if(qq) pr("%d\n",qq);
        else pr("Impossible\n");
    }
    return 0;
}
