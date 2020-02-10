#include<bits/stdc++.h>
using namespace std;
string s1,s2,ans[102][102];
int sz,sz1,lc[102][102];
void lcs()
{
    int i,j;
    for(i=0;i<101;i++)
    {
        lc[0][i]=0;
        lc[i][0]=0;
        ans[0][i]="";
        ans[i][0]="";
    }
    for(i=1; i<=sz; i++)
    {
        for(j=1; j<=sz1; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                lc[i][j] = 1+lc[i-1][j-1];
                ans[i][j] = ans[i-1][j-1]+s1[i-1];
            }
            else if(lc[i-1][j]>lc[i][j-1])
            {
                lc[i][j] = lc[i-1][j];
                ans[i][j] = ans[i-1][j];
            }
            else if(lc[i][j-1]>lc[i-1][j])
            {
                lc[i][j] = lc[i][j-1];
                ans[i][j] = ans[i][j-1];
            }
            else
            {
                lc[i][j] = lc[i][j-1];
                ans[i][j] = min(ans[i-1][j],ans[i][j-1]);
            }
        }
    }
}
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(T--)
    {
        cin>>s1>>s2;
        sz = s1.size();
        sz1 = s2.size();
        lcs();
        printf("Case %d: ",t++);
        if(lc[sz][sz1]==0) printf(":(\n");
        else cout<<ans[sz][sz1]<<endl;
    }
    return 0;
}
