#include<bits/stdc++.h>
using namespace std;
int n,m,a[1002],sm,mx;
void bina_sea()
{
    int st=mx,ed=sm,md,i,cnt,p;
    while(st<=ed)
    {
        cnt=0;
        p=0;
        md = (st+ed)/2;
        for(i=0;i<n;i++)
        {
            if(p+a[i]<=md) p+=a[i];
            else
            {
                cnt++;
                p = a[i];
            }
        }
        if(p>0) cnt++;
        //cout<<"Cap = "<<md<<" Container = "<<cnt<<endl;
        if(cnt<=m) ed = md-1;
        else st = md+1;
    }
    if(cnt>m) md++;
    printf("%d\n",md);
}
int main()
{
    //freopen("1076in.txt","r",stdin);
    //freopen("1076out.txt","w",stdout);
    int i,j,q,T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        sm=0;
        mx=0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            mx = max(mx,a[i]);
            sm+=a[i];
        }
        printf("Case %d: ",t++);
        bina_sea();
    }
}
