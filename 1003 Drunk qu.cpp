#include<bits/stdc++.h>
using namespace std;
vector<int>v[10005],lst;
queue<int>qu;
int main()
{
    string s1,s2;
    map<string,int>mp;
    int n,m,i,j,p,q,cost[10005],tsk,ind,t,T;
    cin>>T;
    for(t=1; t<=T; t++)
    {
        cin>>n;
        ind=1;
        lst.clear();
        mp.clear();
        memset(cost,0,sizeof(cost));
        memset(v,0,sizeof(v));
        for(i=0; i<n; i++)
        {
            cin>>s1>>s2;
            if(mp[s1]==0) mp[s1]=ind++;
            if(mp[s2]==0) mp[s2]=ind++;
            p=mp[s1];
            q=mp[s2];
            v[p].push_back(q);
            cost[q]++;
        }
        for(i=1; i<ind; i++)
        {
            if(cost[i]==0) qu.push(i);
        }
        while(!qu.empty())
        {
            tsk=qu.front();
            lst.push_back(tsk);
            qu.pop();
            for(j=0; j<v[tsk].size(); j++)
            {
                int ff=v[tsk][j];
                cost[ff]--;
                if(cost[ff]==0) qu.push(ff);
            }
        }
        //cout<<lst.size()<<endl;
        //for(i=0;i<lst.size();i++) cout<<lst[i]<<" "; cout<<endl;
        if(lst.size()==ind-1) cout<<"Case "<<t<<": Yes"<<endl;
        else cout<<"Case "<<t<<": No"<<endl;
    }
    return 0;
}

