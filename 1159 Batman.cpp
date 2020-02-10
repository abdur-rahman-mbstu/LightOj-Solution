#include<bits/stdc++.h>
using namespace std;
char s[55],s1[55],s2[55];
int dp[51][51][51];
int lcs(int i, int j, int k)
{
    int a=0,b=0,c=0,d=0,f=0,e=0;
    if(s[i]=='\0'||s1[j]=='\0'||s2[k]=='\0') return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(s[i]==s1[j]&&s[i]==s2[k]) dp[i][j][k] = 1+lcs(i+1,j+1,k+1);
    else
    {
        a = lcs(i,j,k+1);
        b = lcs(i,j+1,k);
        c = lcs(i,j+1,k+1);
        d = lcs(i+1,j,k);
        e = lcs(i+1,j,k+1);
        f = lcs(i+1,j+1,k);
        dp[i][j][k] = max(a,max(b,max(c,max(d,max(e,f)))));
    }
    return dp[i][j][k];
}
int main()
{
    int T,t=1;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        getchar();
        memset(dp,-1,sizeof(dp));
        gets(s);
        gets(s1);
        gets(s2);
        printf("Case %d: %d\n",t++,lcs(0,0,0));
    }
    return 0;
}
