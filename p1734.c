#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int sum_divisor(int s)
{
    int sum=0;
    for (int i=1;i<s;i++)
    {
        if (s%i==0)
        sum+=i;
    }
    return sum;
}
int main(){
    int s;
    scanf("%d",&s);
    int*dp=(int*)calloc(s+1,sizeof(int));
    for (int i=1;i<=s;i++)
    {
        for (int k=s;k>=0;k--)
        {
            if (k<i) break;
            if (dp[k]<dp[k-i]+sum_divisor(i))
            dp[k]=dp[k-i]+sum_divisor(i);
        }
    }
    printf("%d",dp[s]);
    free(dp);
    return 0;
}