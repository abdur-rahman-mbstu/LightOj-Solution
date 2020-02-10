#include<bits/stdc++.h>
#define pi 2*acos(0.0)
using namespace std;
int main()
{
    int T,t=1;
    double r1,r2,h,p,vol,r3;
    cin>>T;
    while(T--)
    {
        cin>>r1>>r2>>h>>p;
        r3 = r1-((h-p)*((r1-r2)/h));
        vol = (pi/3)*(r2*r2+r2*r3+r3*r3)*p;
        printf("Case %d: %.8lf\n",t++,vol);
    }
    return 0;
}
