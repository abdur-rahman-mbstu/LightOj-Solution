#include<bits/stdc++.h>
using namespace std;
int main()
{
    char st[105][25];
    int a[105],b[105],c[105],vo[105],i,p,q,T,t,k,n,co[105];
    cin>>T;
    for(t=1; t<=T; t++)
    {
        k=0;
        cin>>n;
        getchar();
        for(i=0; i<n; i++)
            scanf("%s %d%d%d",st[i],&a[i],&b[i],&c[i]);
        for(i=0; i<n; i++)
            vo[i]=a[i]*b[i]*c[i];
        for(i=0; i<n; i++)
            co[i]=vo[i];
        sort(vo,vo+n);
        for(i=0; i<n; i++)
        {
            if(co[i]==vo[0])
                p=i;
            if(co[i]==vo[n-1])
                q=i;
        }
        cout<<"Case "<<t<<": ";
        if(vo[0]==vo[n-1])
            cout<<"no thief"<<endl;
        else
            cout<<st[q]<<" took chocolate from "<<st[p]<<endl;
    }
    return 0;
}
