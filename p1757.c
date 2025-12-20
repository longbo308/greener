#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int bag01(int*weight,int*value,int*sort,int n,int m)
{
    int max_sort=0;
    for (int i=0;i<n;i++)
    {
        if (sort[i]>max_sort)
        max_sort=sort[i];
    }
    int**dp=(int**)calloc(max_sort+1,sizeof(int*));//注意数组越界，十分小心
    for (int i=0;i<=max_sort;i++)
    {
        dp[i]=(int*)calloc(m+1,sizeof(int));
    }
    for (int i=1;i<=max_sort;i++)
    {
        for (int j=0;j<=m;j++)
        {
            dp[i][j]=dp[i-1][j];
        }
        for (int k=0;k<n;k++)
        {
            if (sort[k]==i)
            {
                for (int j=m;j>=weight[k];j--)
                {
                    if (dp[i][j]<dp[i-1][j-weight[k]]+value[k])
                    dp[i][j]=dp[i-1][j-weight[k]]+value[k];
                }
            }
        }
    }
int result=dp[max_sort][m];
for (int i=0;i<=max_sort;i++)
    {
        free(dp[i]);
    }
    free(dp);
    return result;
}
int main(){
    int n,m;
    scanf("%d %d",&m,&n);
    int*weight=(int*)calloc(n,sizeof(int));
    int*value=(int*)calloc(n,sizeof(int));
    int*sort=(int*)calloc(n,sizeof(int));
    for (int i=0;i<n;i++)
    {
        scanf("%d %d %d",weight+i,value+i,sort+i);
    }
    int result=bag01(weight,value,sort,n,m);
    printf("%d",result);
}