#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sc scanf
#define pr printf
struct info
{
    ll pro,sm;
}tree[300002];
void update(ll node, ll st, ll ed, ll i, ll j, ll vlu)
{
    ll rt,lft,md;
    if(i>ed||j<st) return;
    if(st>=i&&ed<=j)
    {
        tree[node].sm+=(ed-st+1)*vlu;
        tree[node].pro+=vlu;
        return;
    }
    lft = node*2;
    rt = node*2+1;
    md = (st+ed)/2;
    update(lft,st,md,i,j,vlu);
    update(rt,md+1,ed,i,j,vlu);
    tree[node].sm = tree[lft].sm+tree[rt].sm+(ed-st+1)*tree[node].pro;
}
ll quary(ll node, ll st, ll ed, ll i, ll j, ll carry)
{
    ll rt,lft,md,pp,qq;
    if(i>ed||j<st) return 0;
    if(st>=i&&ed<=j) return tree[node].sm+(ed-st+1)*carry;
    lft = node*2;
    rt = node*2+1;
    md = (st+ed)/2;
    pp = quary(lft,st,md,i,j,carry+tree[node].pro);
    qq = quary(rt,md+1,ed,i,j,carry+tree[node].pro);
    return pp+qq;
}
int main()
{
    ll n=0,m,T,t=1,qry,op,x,y,p,i;
    sc("%lld",&T);
    while(T--)
    {
        for(i=1;i<=3*n;i++)
        {
            tree[i].sm=0;
            tree[i].pro=0;
        }
        sc("%lld%lld",&n,&qry);
        pr("Case %lld:\n",t++);
        while(qry--)
        {
            sc("%lld%lld%lld",&op,&x,&y);
            if(op==0)
            {
                sc("%lld",&p);
                update(1,1,n,x+1,y+1,p);
            }
            else pr("%lld\n",quary(1,1,n,x+1,y+1,0));
        }
    }
    return 0;
}
