#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a[100],b[100],pnt,t,T;
    cin>>T;
    for(t=1; t<=T; t++)
    {
        cin>>n;
        pnt=0;
        for(i=0; i<n; i++) cin>>a[i];
        for(i=0; i<n; i++) cin>>b[i];
        sort(a,a+n);
        sort(b,b+n,greater<int>());
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(a[i]>b[j])
                {
                    a[i]=1005;
                    pnt+=2;
                    b[j]=1009;
                    break;
                }
            }
        }
        for(i=0; i<n; i++)
        {
            if(a[i]<=1000)
            {
                for(j=0; j<n; j++)
                {
                    if(a[i]==b[j])
                    {
                        pnt++;
                        b[j]=1009;
                        break;
                    }
                }
            }
        }
        cout<<"Case "<<t<<": "<<pnt<<endl;
    }
    return 0;
}
