#include<bits/stdc++.h>
using namespace std;
double x,y,c;
double chk(double vmi)
{
    double hgt1,hgt2;
    hgt1 = sqrt((x*x-vmi*vmi));
    hgt2 = sqrt((y*y-vmi*vmi));
    //cout<<vmi<<" "<<hgt1<<" "<<hgt2<<endl;
    return (hgt1*hgt2)/(hgt1+hgt2);
}
int main()
{
    int T,t=1,i;
    double st,ed,md,ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf",&x,&y,&c);
        st = 0;
        ed = min(x,y);
        for(i=1;i<=50;i++)
        {
            md = (st+ed)/2.0;
            ans = chk(md);
            //cout<<ans<<endl;
            if(ans>c) st = md;
            else ed = md;
        }
        printf("Case %d: %.10lf\n",t++,md);
    }
}
