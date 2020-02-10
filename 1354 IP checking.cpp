#include<bits/stdc++.h>
#include<math.h>
using namespace std;
long int decimal(long int n)
{
    long int rem,j=0,dec=0;
    while(n!=0)
    {
        rem=n%10;
        n/=10;
        dec=dec+rem*pow(2,j);
        j++;
    }
    return dec;
}
int main()
{
    long int i,j,k,n,a,b,c,d,a1,b1,c1,d1,t,dec1,dec2,dec3,dec4,rem,rem1,rem2,rem3;
    char ch;
    scanf("%ld",&t);
    for(i=1; i<=t; i++)
    {
       long int j=0,p=0,q=0;
       scanf("%ld.%ld.%ld.%ld%ld.%ld.%ld.%ld",&a,&b,&c,&d,&a1,&b1,&c1,&d1);
       dec1=decimal(a1);dec2=decimal(b1);dec3=decimal(c1);dec4=decimal(d1);
       if(a==dec1&&b==dec2&&c==dec3&&d==dec4)
       printf("Case %ld: Yes\n",i);
       else
       printf("Case %ld: No\n",i);
    }
    return 0;
}
