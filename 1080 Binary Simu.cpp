#include<bits/stdc++.h>
using namespace std;
int a[100002];
struct info
{
    int x,prop;
}tree[300003];
void build(int node,int st, int ed)
{
    int md,lft,rgt;
    if(st==ed)
    {
        tree[node].x=a[st];
        return;
    }
    md=(st+ed)/2;
    lft = node*2;
    rgt = lft+1;
    build(lft,st,md);
    build(rgt,md+1,ed);
}
void update(int node, int st, int ed, int i, int j)
{
    int md,rgt,lft;
    if(i>ed||j<st) return;
    if(st>=i&&ed<=j)
    {
        tree[node].prop++;
        return;
    }
    md = (st+ed)/2;
    lft = node*2;
    rgt = lft+1;
    update(lft,st,md,i,j);
    update(rgt,md+1,ed,i,j);
}
int quary(int node, int st, int ed, int i, int carry)
{
    int rt,lft,md,pp=0,qq=0;
    if(st>i||ed<i) return 0;
    if(st==ed&&st==i) return carry+tree[node].prop;
    //else return
    lft = node*2;
    rt = node*2+1;
    //cout<<st<<" "<<ed<<" "<<carry<<endl;
    md = (st+ed)/2;
    pp = quary(lft,st,md,i,carry+tree[node].prop);
    qq = quary(rt,md+1,ed,i,carry+tree[node].prop);
    return pp+qq;
}
int main()
{
    char s[100002],ch;
    int i,j,n,T,t=1,sz,p,q,qry,ans;
    scanf("%d",&T);
    while(T--)
    {
        for(i=1;i<=300000;i++) tree[i].prop=0;
        scanf("%s",s);
        sz = strlen(s);
        for(i=0;i<sz;i++) a[i+1]=s[i]-'0';
        build(1,1,sz);
        scanf("%d",&qry);
        printf("Case %d:\n",t++);
        while(qry--)
        {
            getchar();
            scanf("%c",&ch);
            if(ch=='I')
            {
                scanf("%d%d",&p,&q);
                update(1,1,sz,p,q);
            }
            else
            {
                scanf("%d",&p);
                ans=quary(1,1,sz,p,0);
                printf("%d\n",(a[p]+ans)%2);
            }
        }
    }
    return 0;
}
