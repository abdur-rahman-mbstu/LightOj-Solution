#include<bits/stdc++.h>
using namespace std;
vector<int>v[20003];
queue<int>q;
int colr[20003];
set<int>st;
set<int>::iterator it;
int bfs(int sc)
{
    int i,j,vv,blk=0,red=0,uu;
    if(colr[sc]==0)
    {
        q.push(sc);
        colr[sc]=1;
        blk++;
    }
    while(!q.empty())
    {
        uu = q.front();
        q.pop();
        for(i=0; i<v[uu].size(); i++)
        {
            vv = v[uu][i];
            if(colr[vv]==0)
            {
                if(colr[uu]==1)
                {
                    colr[vv]=2;
                    red++;
                }
                else
                {
                    colr[vv]=1;
                    blk++;
                }
                q.push(vv);
            }
        }
    }
    return max(blk,red);
}
int main()
{
    int T,t=1,i,j,a,b,mx,nf;
    cin>>T;
    while(T--)
    {
        mx = 0;
        st.clear();
        for(i=0; i<=20000; i++)
        {
            v[i].clear();
            colr[i]=0;
        }
        cin>>nf;
        while(nf--)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
            st.insert(a);
            st.insert(b);
        }
        for(it=st.begin(); it!=st.end(); it++)
        {
            mx+=bfs(*it);
        }
        cout<<"Case "<<t++<<": "<<mx<<endl;
    }
    return 0;
}
