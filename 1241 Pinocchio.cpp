#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,T,t=1,i,fal,a[15],m;
    cin>>T;
    while(T--)
    {
        a[0]=2;
        cin>>n;
        for(i=1;i<=n;i++) cin>>a[i];
        fal = 0;
        for(i=1;i<=n;i++)
        {
            if(a[i]>a[i-1])
            {
                m = (a[i]-a[i-1])/5;
                if((a[i]-a[i-1])%5!=0) m++;
                fal+=m;
            }
        }
        cout<<"Case "<<t++<<": "<<fal<<endl;
    }
    return 0;
}
