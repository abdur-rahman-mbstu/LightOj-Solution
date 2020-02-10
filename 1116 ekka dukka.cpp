#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,j,T,k,t;
    cin>>T;
    for(t=1; t<=T; t++)
    {
        j=0;
        cin>>n;
        printf("Case %lld: ",t);
        for(i=2; i<=n/2+1; i=i+i)
        {
            k=n/i;
            if(n%i==0&&k%2!=0)
            {
                printf("%lld %lld\n",k,i);
                j=1;
                break;
            }
        }
        if(j==0)
            cout<<"Impossible"<<endl;
    }
    return 0;
}
