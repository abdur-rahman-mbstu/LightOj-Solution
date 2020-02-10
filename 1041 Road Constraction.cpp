#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
struct info
{
    int u,v,w;
} in[100];
int pr[1000];
bool cmp(info a, info b)
{
    return a.w<b.w;
}
int fnd(int r)
{
    if(pr[r]==r) return r;
    else return pr[r]=fnd(pr[r]);
}
void krskl(int n, int m)
{
    int sm=0,cnt=0,i,p,q,kk=0;
    for(i=0; i<=100; i++) pr[i] = i;
    for(i=0; i<n; i++)
    {
        p = fnd(in[i].u);
        q = fnd(in[i].v);
        if(p!=q)
        {
            sm+=in[i].w;
            pr[p] = q;
            cnt++;
            if(cnt==m-1)
            {
                kk=1;
                break;
            }
        }
    }
    //cout<<cnt<<" "<<sm<<endl;
    if(kk==0) cout<<"Impossible"<<endl;
    else  cout<<sm<<endl;
}
int main()
{
    int T,t=1,i,j,cst,ind,n;
    char s[100],s1[100];
    scanf("%d",&T);
    while(T--)
    {
        mp.clear();
        ind=1;
        scanf("%d",&n);
        getchar();
        for(i=0; i<n; i++)
        {
            scanf("%s %s %d",s,s1,&cst);
            if(mp[s]==0) mp[s]=ind++;
            if(mp[s1]==0) mp[s1]=ind++;
            in[i].u = mp[s];
            in[i].v = mp[s1];
            in[i].w = cst;
        }
        printf("Case %d: ",t++);
        sort(in,in+n,cmp);
        krskl(n,ind-1);
    }
    return 0;
}

