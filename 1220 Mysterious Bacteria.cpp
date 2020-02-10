#include<bits/stdc++.h>
#define mx 43000
using namespace std;
bool check[mx];
long a[mx],k=0;
/*void prime()
{
    long i,j;
    for(i=3; i<=mx; i+=2) check[i]=true;
    for(i=3; i*i<=mx; i+=2)
    {
        if(check[i]==true)
        {
            for(j=i*i; j<=mx; j+=i+i)
                check[j]=false;
        }
    }
    a[k++]=2;
    for(i=3; i<=mx; i+=2)
        if(check[i]==true) a[k++]=i;
}*/
int main()
{
    //prime();
    long long n,i,j,m,p,T,t,cnt;
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        p=1;
        scanf("%lld",&n);
        j=0;
        if(n<0) {n=-n;j=1;}
        for(i=2; i*i<=n; i++)
        {
            cnt=0;
            m=n;
            while(m%i==0)
            {
                cnt++;
                m/=i;
            }
            if(m==1)
            {
                if((j&&cnt&1)||j==0){
                p=cnt;
                break;
                }
            }
        }
        printf("Case %lld: %lld\n",t,p);
    }
    return 0;
}
