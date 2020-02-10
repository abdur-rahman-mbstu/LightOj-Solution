#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[20];
    int n,m,i,j,p,a[105],b[105],T,t;
    cin>>T;
    for(t=1; t<=T; t++)
    {
        cin>>n>>m;
        j=0;
        cout<<"Case "<<t<<":"<<endl;
        for(i=0; i<m; i++)
        {
            cin>>s;
            if(strcmp(s,"pushLeft")==0||strcmp(s,"pushRight")==0)
            {
                j++;
                cin>>p;
                if(strcmp(s,"pushRight")==0)
                {
                    if(j>=n+1)
                    {
                        cout<<"The queue is full"<<endl;
                        j--;
                    }
                    else
                    {
                        a[j]=p;
                        cout<<"Pushed in right: "<<p<<endl;
                    }
                }
                else
                {
                    if(j>=n+1)
                    {
                        cout<<"The queue is full"<<endl;
                        j--;
                    }
                    else
                    {
                        cout<<"Pushed in left: "<<p<<endl;
                        for(int y=2; y<=j; y++)
                            b[y]=a[y-1];
                        a[1]=p;
                        for(int y=2; y<=j; y++)
                            a[y]=b[y];
                    }
                }
            }
            else
            {
                if(strcmp(s,"popLeft")==0)
                {
                    if(j==0)   cout<<"The queue is empty"<<endl;
                    else
                    {
                        cout<<"Popped from left: "<<a[1]<<endl;
                        a[1]=0;
                        for(int y=1; y<j; y++)
                            b[y]=a[y+1];
                        for(int y=1; y<j; y++)
                            a[y]=b[y];
                        j--;
                    }
                }
                else
                {
                    if(j==0)  cout<<"The queue is empty"<<endl;
                    else
                    {
                        cout<<"Popped from right: "<<a[j]<<endl;
                        a[j]=0;
                        j--;
                    }
                }
            }
            /*for(int r=1; r<=j; r++)
                cout<<a[r]<<" ";
            cout<<endl;*/
        }
    }
    return 0;
}
