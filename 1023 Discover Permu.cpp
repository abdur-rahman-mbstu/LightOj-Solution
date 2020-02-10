#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[30];
    int i,j,n,m,k,T,t=1;
    cin>>T;
    while(T--)
    {
        int cnt=0;
        cin>>n>>k;
        for(i=0;i<n;i++) s[i]=i+'A';
        s[i]='\0';
        cout<<"Case "<<t++<<":"<<endl;
        do
        {
            cnt++;
            cout<<s<<endl;
            if(cnt==k) break;
        }while(next_permutation(s,s+n));
    }
    return 0;
}
