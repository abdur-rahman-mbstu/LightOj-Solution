#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,t=1;
    scanf("%d",&T);
    double a,b,r,s,theta,x;
    while(T--)
    {
        scanf("%lf : %lf",&a,&b);
        r = (sqrt(a*a+b*b))/2.0;
        theta = acos((2*r*r-b*b)/(2*r*r));
        s = r*theta;
        x = 400/(2*a+2*s);
        printf("Case %d: %.10lf %.10lf\n",t++,a*x,b*x);
    }
    return 0;
}
