#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long int f(int m,int t,int*time,int*value)
{
   long long int*dp=(long long int*)calloc(t+1,sizeof(long long int));
    dp[0]=0;
    for (int i=1;i<=m;i++)
    {
        for (int j=time[i];j<=t;j++)
        {
            if (dp[j]<(dp[j-time[i]]+value[i]))
            dp[j]=dp[j-time[i]]+value[i];
        }
    }
    long long int result=dp[t];
    free(dp);
    return result;
}
int main(){
    int m,t;
    scanf("%d %d",&t,&m);
    int *time=(int*)calloc(m+1,sizeof(int));
    int*value=(int*)calloc(m+1,sizeof(int));
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",time+i,value+i);
    }
    printf("%lld",f(m,t,time,value));
}