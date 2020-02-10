#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,p,q,a[2005],T,t=1,cnt;
    scanf("%d",&T);
    while(T--)
    {
        cnt=0;
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        //for(i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                p = a[i]+a[j];
                q = upper_bound(a,a+n,p-1)-a;
                //cout<<a[i]<<" "<<a[j]<<" q = "<<q<<"  j = "<<j<<endl;
                cnt+=q-j-1;
            }
        }
        printf("Case %d: %d\n",t++,cnt);
    }
}
