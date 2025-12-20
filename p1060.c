#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int f(int n,int m,int*price,int*right)
{
    int*dp=(int*)calloc(n+1,sizeof(int));
    for (int i=1;i<=m;i++)
    {
        int temp=price[i]*right[i];
        for (int j=n;j>=price[i];j--)
        {
            if (dp[j]<(dp[j-price[i]]+temp))
            dp[j]=dp[j-price[i]]+temp;
        }
    }
    int result=dp[n];
    free(dp);
    return result;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int*price=(int*)malloc((m+1)*sizeof(int));
    int*right=(int*)malloc((m+1)*sizeof(int));
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",price+i,right+i);
    }
    printf("%d",f(n,m,price,right));
    free(price);
    free(right);
    return 0;
}