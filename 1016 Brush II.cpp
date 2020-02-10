#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct info
{
    ll x,y;
}in[50002];
bool cmp(info a, info b)
{
    return a.y<b.y;
}
int main()
{
    ll n,m,i,j,T,t=1,w,cnt,cur;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&w);
        for(i=0;i<n;i++) scanf("%lld%lld",&in[i].x,&in[i].y);
        sort(in,in+n,cmp);
        //for(i=0;i<n;i++) cout<<in[i].x<<" "<<in[i].y<<endl;
        j=0;
        cnt=0;
        while(j<n)
        {
            //cout<<j<<endl;
            cur =in[j].y+w;
            cnt++;
            for(i=j;i<n;i++)
            {
                if(in[i].y>cur) break;
            }
            j=i;
        }
        printf("Case %lld: %lld\n",t++,cnt);
    }
}
