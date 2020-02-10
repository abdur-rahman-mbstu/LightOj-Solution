#include<bits/stdc++.h>
using namespace std;
int a[100005],tree[300050];

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
    tree[node]=min(tree[lf],tree[rt]);
    //cout<<tree[node]<<" "<<node<<endl;
}

int qury(int node, int beg, int ed, int fst, int lst)
{
    int lf,rt,md,p=100006,p1=100000;
    if(fst>ed||lst<beg) return min(p,p1);
    if(beg>=fst&&ed<=lst) return tree[node];
    lf=node*2;
    rt=node*2+1;
    md=(beg+ed)/2;
    p=qury(lf,beg,md,fst,lst);
    p1=qury(rt,md+1,ed,fst,lst);
    return min(p,p1);
}

int main()
{
    int i,j,n,p,q,sm,mn,m,T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=1; i<=n; i++) scanf("%d",&a[i]);
        fun(1,1,n);
        printf("Case %d:\n",t++);
        while(m--)
        {
            scanf("%d%d",&p,&q);
            mn=qury(1,1,n,p,q);
            printf("%d\n",mn);
        }
    }
    return 0;
}

