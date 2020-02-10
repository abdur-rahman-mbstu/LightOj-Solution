#include<bits/stdc++.h>
using namespace std;
struct info
{
    int val,dv;
} in[1005];
bool cmp(info a,info b)
{
    if(a.dv==b.dv) return a.val>b.val;
    return a.dv<b.dv;
}
void pre()
{
    int n,i,j,cnt,num[1005],div[1005];
    div[1]=1;
    for(i=2; i<=1000; i++)
    {
        cnt=0;
        for(j=1; j*j<=i; j++)
        {
            if(i%j==0)
            {
                if(j==i/j) cnt++;
                else cnt+=2;
            }
        }
        //num[i]=i;
        div[i]=cnt;
    }
    for(i=1; i<=1000; i++)
    {
        in[i].val=i;
        in[i].dv=div[i];
    }
    sort(in+1,in+1001,cmp);
}
int main()
{
    pre();
    int n,T,t;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>n;
        cout<<"Case "<<t<<": "<<in[n].val<<endl;
    }
    return 0;
}
