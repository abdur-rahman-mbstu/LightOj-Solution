#include<bits/stdc++.h>
using namespace std;
vector<int>v[10005],lst;
queue<int>qu;
map<string,int>mp;
int main()
{
    string s1,s2;
    int n,m,i,j,p,q,cost[10005],tsk,vis[10005],T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>n;
        int k=0,ind=1;
        lst.clear();
        mp.clear();
        memset(cost,0,sizeof(cost));
        memset(v,0,sizeof(v));
        memset(vis,0,sizeof(vis));
        for(i=0; i<n; i++)
        {
            cin>>s1>>s2; if(mp[s1]==0) mp[s1]=ind++; if(mp[s2]==0) mp[s2]=ind++;
            p=mp[s1];
            q=mp[s2];
            v[p].push_back(q);
            cost[q]++;
        }
        for(i=1; i<ind; i++)
        {
            for(j=1; j<ind; j++)
            {
                if(cost[j]==0&&vis[j]==0)
                {
                    vis[j]=1;
                    lst.push_back(j);
                    for(int f=0; f<v[j].size(); f++) cost[v[j][f]]--;
                    break;
                }
            }
        }
        if(lst.size()==ind-1) cout<<"Case "<<t<<": Yes"<<endl;
        else cout<<"Case "<<t<<": No"<<endl;
    }
    return 0;
}
