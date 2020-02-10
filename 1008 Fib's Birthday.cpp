#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,p,r,c,T,t;
    cin>>T;
    for(t=1; t<=T; t++)
    {
        cin>>n;
        p=ceil(sqrt(n));
        if(p&1)
        {
            if(p*p-n<p)
            {
                c=p;
                r=p*p-n+1;
            }
            else
            {
                c=n-((p-1)*(p-1));
                r=p;
            }
        }
        else
        {
            if(p*p-n<p)
            {
                r=p;
                c=p*p-n+1;
            }
            else
            {
                r=n-((p-1)*(p-1));
                c=p;
            }
        }
        printf("Case %lld: %lld %lld\n",t,r,c);
    }
    return 0;
}
