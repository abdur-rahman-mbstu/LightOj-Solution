#include<bits/stdc++.h>
#define mx 9999992
using namespace std;
bool check[mx];
int arr[664580],k=0;

void prime()
{
    int i,j;
    for(i=3; i<=mx; i+=2)
        check[i]=true;
    for(i=3; i*i<=mx; i+=2)
    {
        if(check[i]==true)
        {
            for(j=i*i; j<=mx; j+=i+i)
                check[j]=false;
        }
    }
    arr[k++]=2;
    for(i=3; i<=mx; i+=2)
    {
        if(check[i]==true)
            arr[k++]=i;
    }
   // cout<<k<<endl;
}

int main()
{
    prime();
    int n,i,T,t,hg,cnt,p,lw;
    cin>>T;
    for(t=1; t<=T; t++)
    {
        cnt=0;
        cin>>n;
        if(n==4)
        {
            cout<<"Case "<<t<<": "<<1<<endl;
            continue;
        }
        lw=lower_bound(arr,arr+k,n)-arr;
        //cout<<hg<<" "<<lw<<"  "<<arr[lw]<<endl;
        for(i=1; i<=lw; i++)
        {
            p=n-arr[i];
            if(p<arr[i]) break;
            if(check[p]==true) cnt++;
        }
        cout<<"Case "<<t<<": "<<cnt<<endl;
    }
    return 0;
}
