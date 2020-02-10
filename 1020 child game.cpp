#include<stdio.h>
#include<string.h>
main()
{
    char str[10];
    int i,d,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%s",&d,str);
        if(strcmp(str,"Alice")==0)
        {
            if(d%3==1)
                printf("Case %d: Bob\n",i);
            else
                printf("Case %d: Alice\n",i);
        }
        else
        {
            if(d%3==0)
                printf("Case %d: Alice\n",i);
            else
                printf("Case %d: Bob\n",i);
        }
    }
    return 0;
}
