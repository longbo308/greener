#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int start,end;
    int n,m;
    int min=0x3f3f3f3f;
    scanf("%d %d",&n,&m);
    int arr[n+1];
    arr[0]=0;
    for (int i=1;i<=n;i++)
        scanf("%d",arr+i);
    int last[n+1];
    memset(last,0,sizeof(last));
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=i;j++)
            last[i]+=arr[j];
    }
    for (start=1;start+m-1<=n;start++)
    {
        end=start+m-1;
        if((last[end]-last[start-1])<min)
            min=last[end]-last[start-1];
    }
    printf("%d",min);
}