#include<bits/stdc++.h>
#define pi 2*acos(0.0)
using namespace std;
int main()
{
    double a1,a2,b1,b2,o1,o2,r,x,dis,m;
    int i,T;
    cin>>T;
    for(i=1; i<=T; i++)
    {
        cin>>o1>>o2>>a1>>a2>>b1>>b2;
        if(o1==o2==a1==a2==b1==b2)
        {
            printf("Case %d: 0.00000000\n",i);
            continue;
        }
        r=sqrt((o1-a1)*(o1-a1)+(o2-a2)*(o2-a2));
        m=sqrt((a1-b1)*(a1-b1)+(a2-b2)*(a2-b2));
        x=asin(m/(2*r));
        dis=2*r*x;
        printf("Case %d: %.8lf\n",i,dis);
    }
    return 0;
}
