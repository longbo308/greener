#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MOD 10000
int main (){
    int n,k;
    scanf("%d %d",&n,&k);
    int dp[1005];
    int pre[1005];
    int last_pre[1005];
    memset(last_pre,0,sizeof(last_pre));
    last_pre[0]=1;//存储上一行的信息（避免了二维数组）
    for (int j=1;j<=k;j++)
        last_pre[j]=1;//只有一个数时，规定前缀和为1
    for (int i=2;i<=n;i++)
    {
        dp[0]=1;
        pre[0]=1;
        for (int j=1;j<=k;j++)
        {
            int start=(j-i+1)>0?(j-i+1):0;
            if (start==0)
                dp[j]=last_pre[j]%MOD;
            else
                dp[j]=(last_pre[j]-last_pre[start-1]+MOD)%MOD;
            pre[j]=(pre[j-1]+dp[j])%MOD;
        }
        for (int j=0;j<=k;j++)
        last_pre[j]=pre[j];
    }
    if(n==1)
    printf("%d\n",(k==0)?1:0);
    else
        printf("%d\n",dp[k]%MOD);
    return 0;
}