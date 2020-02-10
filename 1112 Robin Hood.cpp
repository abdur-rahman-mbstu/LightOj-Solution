#include<bits/stdc++.h>
using namespace std;
int a[100005],tree[300050],kk;

void fun(int node, int beg, int ed)
{
    int lf,rt,md;
    if(ed==beg)
    {
        tree[node]=a[ed];
        return;
    }
    lf=node*2;
    rt=node*2+1;
    md=(beg+ed)/2;
    fun(lf,beg,md);
    fun(rt,md+1,ed);
    tree[node]=tree[lf]+tree[rt];
    //cout<<tree[node]<<" "<<node<<endl;
}

void update(int node, int beg, int ed, int idx, int vv,int op)
{
    int lf,rt,md;
    if(idx>ed||idx<beg) return;
    if(ed==beg)
    {
        kk=tree[node];
        if(op==1) tree[node]=vv;
        else tree[node]=tree[node]+vv;
        return;
    }
    lf=node*2;
    rt=node*2+1;
    md=(beg+ed)/2;
    update(lf,beg,md,idx,vv,op);
    update(rt,md+1,ed,idx,vv,op);
    tree[node]=tree[lf]+tree[rt];
    //cout<<tree[node]<<" "<<node<<endl;
}

int qury(int node, int beg, int ed, int fst, int lst)
{
    int lf,rt,md,p,p1;
    if(fst>ed||lst<beg) return 0;
    if(beg>=fst&&ed<=lst) return tree[node];
    lf=node*2;
    rt=node*2+1;
    md=(beg+ed)/2;
    p=qury(lf,beg,md,fst,lst);
    p1=qury(rt,md+1,ed,fst,lst);
    return p+p1;
}

int main()
{
    int i,j,n,p,q,sm,op,idx,vv,op1,T,t=1,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=1; i<=n; i++) scanf("%d",&a[i]);
        printf("Case %d:\n",t++);
        fun(1,1,n);
        while(m--)
        {
            kk=0;
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d",&idx);
                update(1,1,n,idx+1,0,op);
                printf("%d\n",kk);
            }
            else if(op==2)
            {
                scanf("%d%d",&idx,&vv);
                update(1,1,n,idx+1,vv,op);
                //sm=qury(1,1,n,1,n);
                //printf("%d\n",sm);
            }
            else
            {
                scanf("%d%d",&idx,&vv);
                sm=qury(1,1,n,idx+1,vv+1);
                printf("%d\n",sm);
            }
        }
    }
    return 0;
}
