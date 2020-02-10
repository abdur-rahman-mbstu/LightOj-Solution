#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[100][100],s1[100];
    int i,j,p,T,m;
    cin>>T;
    getchar();
    for(int t=1; t<=T; t++)
    {
        p=0;
        m=0;
        printf("Case %d:\n",t);
        strcpy(s[0],"http://www.lightoj.com/");
        while(1)
        {
            cin>>s1;
            if(strcmp(s1,"VISIT")==0)
            {
                p++;
                cin>>s[p];
                cout<<s[p]<<endl;
                m=p;
            }
            else if(strcmp(s1,"BACK")==0)
            {
                 p--;
                if(p<0)
                {
                    cout<<"Ignored"<<endl;
                    p=0;
                }
                else cout<<s[p]<<endl;
            }
            else if(strcmp(s1,"FORWARD")==0)
            {
                p++;
                if(p>m)
                {
                    cout<<"Ignored"<<endl;
                    p=m;
                }
                else cout<<s[p]<<endl;
            }
            else break;
        }
    }
    return 0;
}
