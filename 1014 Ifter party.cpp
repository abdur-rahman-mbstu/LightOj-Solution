#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n,m,i,j,T,t,dif,p;
    set<long>st;
    cin>>T;
    for(t=1; t<=T; t++)
    {
        st.clear();
        cin>>n>>m;
        dif=n-m;
        j=0;
        for(i=1; i*i<=dif; i++)
        {
            if(dif%i==0)
            {
                p=dif/i;
                if(i>m) {st.insert(i);j=1;}
                if(p>m) {st.insert(p);j=1;}
            }
        }
        printf("Case %ld:",t);
        if(j==0) cout<<" impossible"<<endl;
        else
        {
            for(typeof(st.begin())i=st.begin(); i!=st.end(); i++)
                cout<<" "<<*i;
            cout<<endl;
        }
    }
    return 0;
}
