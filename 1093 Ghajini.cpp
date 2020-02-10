#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct info
{
    int mx,mn;
}tree[300002];
int a[100003],mxx,mnn;
void build(int node, int st, int ed)
{
    int lft,rgt,md;
    if(st==ed)
    {
        tree[node].mx=a[st];
        tree[node].mn=a[st];
        return;
    }
    md = (st+ed)/2;
    lft = node*2;
    rgt = node*2+1;
    build(lft,st,md);
    build(rgt,md+1,ed);
    tree[node].mx = max(tree[lft].mx,tree[rgt].mx);
    tree[node].mn = min(tree[lft].mn,tree[rgt].mn);
}
void quary(int node, int st, int ed, int i, int j)
{
    int md,lft,rgt;
    if(st>j||ed<i) return;
    if(st>=i&&ed<=j)
    {
        mxx = max(mxx,tree[node].mx);
        mnn = min(mnn,tree[node].mn);
        return;
    }
    md = (st+ed)/2;
    lft = node*2;
    rgt = node*2+1;
    quary(lft,st,md,i,j);
    quary(rgt,md+1,ed,i,j);
}
int main()
{
    int T,t=1,n,i,ans,d;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&d);
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        build(1,1,n);
        ans=0;
        for(i=1;i<=n-d+1;i++)
        {
            mxx=0;
            mnn = 10e8+99;
           quary(1,1,n,i,i+d-1);
           //cout<<mxx<<" "<<mnn<<endl;
           ans = max(ans,mxx-mnn);
        }
        printf("Case %d: %d\n",t++,ans);
    }
}
