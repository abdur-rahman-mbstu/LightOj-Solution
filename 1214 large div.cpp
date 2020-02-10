#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,i,j,num,ll,T,t;
    char str[1000];
    cin>>T;
    getchar();
    for(t=1;t<=T;t++)
    {
        scanf("%s %lld",str,&a);
        num=0;
        for(i=0; i<strlen(str); i++)
        {
            if(str[0]=='-')
            {
                str[i]='0';
            }
            num=(num*10+(str[i]-'0'))%a;
        }
        if(num==0)
            printf("Case %lld: divisible\n",t);
        else
           printf("Case %lld: not divisible\n",t);
    }
    return 0;
}
