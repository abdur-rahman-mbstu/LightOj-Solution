#include<bits/stdc++.h>
using namespace std;
int main()
{
    char st[105],st1[105];
    int co[30],co1[30],i,j,T,t,ll,LL;
    cin>>T;
    getchar();
    for(t=1; t<=T; t++)
    {
        memset(co,0,sizeof(co));
        memset(co1,0,sizeof(co1));
        gets(st);
        gets(st1);
        ll=strlen(st);
        LL=strlen(st1);
        for(i=0; i<ll; i++)
        {
            if(isalpha(st[i]))
            {
                if(st[i]>=65&&st[i]<=90)
                    st[i]=st[i]+32;
                co[st[i]-'a']++;
            }
        }
        for(i=0; i<LL; i++)
        {
            if(isalpha(st1[i]))
            {
                if(st1[i]>=65&&st1[i]<=90)
                    st1[i]=st1[i]+32;
                co1[st1[i]-'a']++;
            }
        }
        cout<<"Case "<<t<<": ";
        int p=0;
        for(i=0; i<26; i++)
        {
            if(co[i]!=co1[i])
            {
                cout<<"No"<<endl;
                p=1;
                break;
            }
        }
        if(p==0)
            cout<<"Yes"<<endl;
    }
    return 0;
}
