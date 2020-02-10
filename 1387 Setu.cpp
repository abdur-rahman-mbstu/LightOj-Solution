#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    long int i,j,n,a,t;
    char str[10];
    cin>>t;
    for(j=1; j<=t; j++)
    {
        cin>>n;
        long int sum=0;
        printf("Case %ld:\n",j);
        for(i=1; i<=n; i++)
        {
            getchar();
            scanf("%s",str);
            if(strcmp(str,"donate")==0)
            {
                scanf("%ld",&a);
                sum=sum+a;
            }
            else if(strcmp(str,"report")==0)
                cout<<sum<<endl;
        }
    }
    return 0;
}
