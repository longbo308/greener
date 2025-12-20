#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
long long f(long long n,int x)
{
    if (n==0) return 1;
    int digit=n==0?0:(int)log10(n);
    long long pow9[20];
    pow9[0]=1;
    for (int i=1;i<=digit+1;i++)
    {
        pow9[i]=pow9[i-1]*9;
    }
    long long int sum=1;
    for (int j=1;j<=digit;j++)
    {
        sum+=8*pow9[j-1];
    }

    int*n_digit=(int*)calloc(digit+1,sizeof(int));
    long long int temp=n;
    for (int i=digit;i>=0;i--)
    {
        n_digit[i]=temp%10;
        temp/=10;
    }
   for (int pos=0;pos<=digit;pos++)
   {
    int current=n_digit[pos];
    int remaining=digit-pos;
    int start=(pos==0)?1:0;
    int valid_less=0;
    for (int d=start;d<current;d++)
    {
        if (d!=x)
        valid_less++;
    }
    sum+=valid_less*pow9[remaining];
    if (current==x)
    {
        free(n_digit);
        return sum;
    }
   }
   free(n_digit);
   sum+=1;
   return sum;
}
int main(){
    int t;
    scanf("%d",&t);
    long long int a1[t];
    int a2[t];
    for (int i=0;i<t;i++)
    {
        scanf("%lld %d",a1+i,a2+i);
    }
    for (int i=0;i<t;i++)
    {
        printf("%lld\n",f(a1[i],a2[i]));
    }
}