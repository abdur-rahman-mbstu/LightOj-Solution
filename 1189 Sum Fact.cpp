#include<bits/stdc++.h>
using namespace std;
long long fct[30];
void fact()
{
    fct[0]=fct[1]=1;
    long long ans,i,j;
    for(i=2; i<=20; i++)
    {
        ans=1;
        for(j=2; j<=i; j++) ans*=j;
        fct[i]=ans;
    }
    //for(i=2; i<=20; i++) cout<<fct[i]<<" ";
}
int main()
{
    fact();
    long long n,i,j,m,p,q,a[100],T,t=1;
    cin>>T;
    while(T--)
    {
        q=0;
        cin>>n;
        for(i=20; i>=0; i--)
        {
            if(n-fct[i]>=0)
            {
                a[q++]=i;
                n-=fct[i];
            }
        }
        cout<<"Case "<<t++<<": ";
        if(n==0)
        {
            for(i=q-1; i>=0; i--)
            {
                if(i==q-1) cout<<a[i]<<"!";
                else cout<<"+"<<a[i]<<"!";
            }
            cout<<endl;
        }
        else cout<<"impossible"<<endl;
    }
    return 0;
}
