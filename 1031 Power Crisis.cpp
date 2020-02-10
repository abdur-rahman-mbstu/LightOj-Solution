#include<bits/stdc++.h>
using namespace std;

int fun(int n, int m)
{
    if(n==1) return 0;
    else return (fun(n-1,m)+m)%n;
}
int main()
{
    int n,m,i,j,a[10003],T,cnt,pos,t=1,p;
    cout<<fun(17,7)<<endl;
    while(cin>>n&&n)
    {
        for(i=2; i<=n; i++)
        {
            p=fun(n,i);
            if(p==12)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
}


