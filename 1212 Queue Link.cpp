#include<bits/stdc++.h>
using namespace std;
struct info
{
    int val;
    struct info *next;
} *head,*ptr,*ptr1;
void addfir(int n);
void addlast(int n);
int main()
{
    int n,cnt,i,T,t,p,m;
    char s[20];
    cin>>T;
    for(t=1; t<=T; t++)
    {
        cnt=0;
        head=NULL;
        cin>>n>>m;
        cout<<"Case "<<t<<":"<<endl;
        for(i=1; i<=m; i++)
        {
            cin>>s;
            if(strcmp(s,"pushLeft")==0||strcmp(s,"pushRight")==0)
            {
                cin>>p;
                if(strcmp(s,"pushLeft")==0)
                {
                    if(cnt==n)  cout<<"The queue is full"<<endl;
                    else
                    {
                        addfir(p);
                        cout<<"Pushed in left: "<<p<<endl;
                        cnt++;
                    }
                }
                else
                {
                    if(cnt==n) cout<<"The queue is full"<<endl;
                    else
                    {
                        addlast(p);
                        cout<<"Pushed in right: "<<p<<endl;
                        cnt++;
                    }
                }
            }
            else
            {
                if(strcmp(s,"popLeft")==0)
                {
                    if(cnt==0)
                    {
                        cout<<"The queue is empty"<<endl;
                        head=NULL;
                    }
                    else
                    {
                        cout<<"Popped from left: "<<head->val<<endl;
                        head=head->next;
                        cnt--;
                    }
                }
                else
                {
                    if(cnt==0)
                    {
                        cout<<"The queue is empty"<<endl;
                        head=NULL;
                    }
                    else
                    {
                        ptr1=ptr=head;
                        if(cnt==1)
                        {
                            cout<<"Popped from right: "<<ptr->val<<endl;
                            head=0;
                        }
                        else
                        {
                            while(ptr->next!=NULL)
                            {
                                ptr1=ptr;
                                ptr=ptr->next;
                            }
                            cout<<"Popped from right: "<<ptr->val<<endl;
                            ptr1->next=NULL;
                        }
                        cnt--;
                    }
                }
            }
           /* ptr=head;
            while(ptr!=NULL)
            {
                cout<<ptr->val<<" ";
                ptr=ptr->next;
            }
            cout<<endl;*/
        }
    }
    return 0;
}

void addfir(int n)
{
    ptr=(struct info*)malloc(sizeof(info));
    ptr->val=n;
    if(head==0)
    {
        head=ptr;
        ptr->next=NULL;
    }
    else
    {
        ptr->next=head;
        head=ptr;
    }
}
void addlast(int n)
{
    ptr=(struct info*)malloc(sizeof(info));
    ptr->val=n;
    ptr->next=NULL;
    if(head==0) head=ptr;
    else
    {
        ptr1=head;
        while(ptr1->next!=NULL)
            ptr1=ptr1->next;
        ptr1->next=ptr;
    }
}
