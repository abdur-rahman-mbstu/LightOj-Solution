#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n,i,p,q,t,T;
    cin>>T;
    for(t=1; t<=T; t++)
    {
        long neg=0,pos=0,sm=0;
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>p;
            if(p<0)
            {
                p=-p;
                neg++;
            }
            else pos++;
            sm+=p;
        }
        cout<<"Case "<<t<<": ";
        q=(__gcd(pos,sm));
        if(neg==n) cout<<"inf"<<endl;
        else printf("%ld/%ld\n",sm/q,pos/q);
    }
    return 0;
}
