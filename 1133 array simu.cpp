#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int arr[105],i,j,n,T,t,m,k,p,q,arr1[105];
    char ch;
    cin>>T;
    for(t=1; t<=T; t++)
    {
        cin>>n>>m;
        for(i=0; i<n; i++)
            cin>>arr[i];
        for(j=0; j<m; j++)
        {
            k=0;
            cin>>ch;
            if(ch=='M')
            {
                cin>>p;
                for(i=0; i<n; i++)
                    arr[i]=arr[i]*p;
            }
            else if(ch=='S')
            {
                cin>>p;
                for(i=0; i<n; i++)
                    arr[i]=arr[i]+p;
            }
            else if(ch=='D')
            {
                cin>>p;
                for(i=0; i<n; i++)
                    arr[i]=arr[i]/p;
            }
            else if(ch=='P')
            {
                cin>>p>>q;
                    swap(arr[p],arr[q]);
            }
           else if(ch=='R')
            {
                for(i=n-1; i>=0; i--)
                    arr1[k++]=arr[i];
                    for(i=0;i<n;i++)
                        arr[i]=arr1[i];
            }
        }
        printf("Case %ld:\n",t);
        for(i=0; i<n; i++)
        {
            if(i!=n-1)
                printf("%ld ",arr[i]);
            else
                printf("%ld\n",arr[i]);
        }
    }
    return 0;
}
