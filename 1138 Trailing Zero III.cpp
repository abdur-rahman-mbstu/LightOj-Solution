#include<bits/stdc++.h>
using namespace std;
int n;
int check(int p)
{
    int q=0;
    while(p!=0)
    {
        p/=5;
        q+=p;
    }
    return q;
}
int bysea()
{
    int fir=0,last=1000000000,mid,ans=0;
    while(fir<=last)
    {
        mid=(fir+last)/2;
        if(check(mid)>n) last=mid-1;
        else if(check(mid)<n) fir=mid+1;
        else
        {
            ans=mid;
            last=mid-1;
        }
    }
    return ans;
}
int main()
{
    int t,T;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>n;
        if(bysea()==0) cout<<"Case "<<t<<": impossible"<<endl;
        else cout<<"Case "<<t<<": "<<bysea()<<endl;
    }
    return 0;
}
