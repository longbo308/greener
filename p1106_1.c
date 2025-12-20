#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXN 255
bool issmaller(char*a,char*b)
{
    int start_a=0;int start_b=0;
    while (a[start_a]=='0'&&a[start_a]!='\0') start_a++;
    while (b[start_b]=='0'&&b[start_b]!='\0') start_b++;
    int len_a=strlen(a+start_a);int len_b=strlen(b+start_b);
    if (len_a!=len_b) return len_a<len_b;
    for (int i=0;i<len_a;i++)
    {
        if (a[i+start_a]!=b[i+start_b])
        {
            return a[i+start_a]<b[i+start_b];
        }
    }
    return false;
}
int main(){
    char num[MAXN];
    int k;
    scanf("%s",num);
    scanf("%d",&k);
    int n=strlen(num);
   static char dp[MAXN][MAXN][MAXN]={0};
    for (int i=0;i<=k;i++)
    {
        dp[i][i][0]='\0';
    }
    for (int i=0;i<=n;i++)
    {
        strncpy(dp[i][0],num,i);
        dp[i][0][i]='\0';
    }
    dp[0][0][0]='\0';
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=k&&j<=i;j++)
        {
            char case1[MAXN];
            if (i-1>=j) 
            {
                strcpy(case1,dp[i-1][j]);
                int len_1=strlen(case1);
                case1[len_1++]=num[i-1];
                case1[len_1]='\0';
            }
            else 
            case1[0]='\0';
            char case2[MAXN];
            if (i-1>=j-1)
            strcpy(case2,dp[i-1][j-1]);
            else 
            case2[0]='\0';
            if (case1[0]=='\0') strcpy(dp[i][j],case2);
            else if (case2[0]=='\0') strcpy(dp[i][j],case1);
            else if (issmaller(case1,case2))
            strcpy(dp[i][j],case1);
            else 
            strcpy(dp[i][j],case2);
        }
    }
    char*result=dp[n][k];
    int start=0;
    while (result[start]=='0'&&result[start+1]!='\0')
    {
        start++;
    }
    if (result[start]=='\0')
    printf("\0\n");
    else 
    printf("%s\n",result+start);
    return 0;

}