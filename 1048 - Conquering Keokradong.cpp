#include<bits/stdc++.h>
using namespace std;
int n,m,a[1003],mx,ans,mn;

void bin_Sea()
{
    int i,st=mn,ed=mx,md,cnt,sm;
    while(st<=ed)
    {
        cnt=0;
        sm=0;
        md = (st+ed)/2;
        for(i=0; i<=n; i++)
        {
            if(sm+a[i]>md)
            {
                cnt++;
                sm = a[i];
            }
            else sm+=a[i];
        }
        if(sm) cnt++;
        if(cnt<=m+1)
        {
            ed = md-1;
            ans = md;
        }
        else st = md+1;
        //cout<<cnt<<" md = "<<md<<endl;
    }
}

void print(int p)
{
    int i,sm=0,cnt=0;
    for(i=0; i<=n; i++)
    {
        if(sm+a[i]>p)
        {
            printf("%d\n",sm);
            sm = a[i];
            cnt++;
        }
        else if(sm+a[i]==p)
        {
            printf("%d\n",sm+a[i]);
            sm = 0;
            cnt++;
        }
        else if(n-i==m-cnt)
        {
            printf("%d\n",sm+a[i]);
            sm = 0;
            cnt++;
        }
        else sm+=a[i];
    }
}

int main()
{
    //freopen("1048in.txt","r",stdin);
    //freopen("1048out.txt","w",stdout);
    int i,j,T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        mx=0;
        mn=0;
        scanf("%d%d",&n,&m);
        for(i=0; i<=n; i++)
        {
            scanf("%d",&a[i]);
            mx+=a[i];
            mn = max(mn,a[i]);
        }
        bin_Sea();
        printf("Case %d: %d\n",t++,ans);
        print(ans);
    }
}
