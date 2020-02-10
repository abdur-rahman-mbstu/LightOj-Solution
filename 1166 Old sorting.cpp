#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a[105],p,i,j,mn,cnt,t,T;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>n;
        cnt=0;
        for(i=0; i<n; i++) cin>>a[i];
        for(i=0; i<n; i++)
        {
            mn=a[i];p=i;
            for(j=i+1; j<n; j++)
            {
                if(a[j]<mn)
                {
                    mn=a[j];
                    p=j;
                }
            }
            swap(a[i],a[p]);
            if(a[i]!=a[p]) cnt++;
        }
        cout<<"Case "<<t<<": "<<cnt<<endl;
    }
    return 0;
}

