#include<bits/stdc++.h>
#define mx 100
using namespace std;
bool check[mx];
int arr[mx+10],a[105],p,co=0;

void prime()
{
    int i,j;
    for(i=3; i<=mx; i+=2)
        check[i]=true;
    for(i=3; i*i<=mx; i+=2)
    {
        if(check[i]==true)
        {
            for(j=i*i; j<=mx; j+=i+i)
                check[j]=false;
        }
    }
    int k=0;
    arr[k++]=2;
    for(i=3; i<=mx; i+=2)
    {
        if(check[i]==true)
            arr[k++]=i;
    }
}
int main()
{
    prime();
    int n,pp,kk,mm,i,j,T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        int cnt[104]= {0},h=0,ll=0,b[105],r=0;
        for(i=n; i>=2; i--)
        {
            pp=i;
            for(j=0; arr[j]*arr[j]<=pp; j++)
            {
                while(pp%arr[j]==0)
                {
                    cnt[arr[j]]++;
                    pp/=arr[j];
                }
            }
            if(pp!=1)
            {
                cnt[pp]++;
            }
        }
        printf("Case %d: %d =",t,n);
        for(i=2; i<=100; i++)
        {
            if(cnt[i]>0)
            {
                if(r==0) printf(" %d (%d)",i,cnt[i]);
                else printf(" * %d (%d)",i,cnt[i]);
                r++;
            }
        }
        printf("\n");
    }
    return 0;
}
