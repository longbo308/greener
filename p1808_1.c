#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    return *(char*)a-*(char*)b;
}
int main(){
    int n;int sort=0;
    scanf("%d",&n);
    char arr[n][101];
    for (int i=0;i<n;i++)
    {
        scanf("%s",arr[i]);
    }
    for (int i=0;i<n;i++)
    {
    int len=strlen(arr[i]);
    qsort(arr[i],len,sizeof(char),cmp);
    }
    int *used=(int*)calloc(n,sizeof(int));
    for (int i=0;i<n;i++)
    {
        if (!used[i])
        {
            used[i]=1;
            sort++;
        
        for (int j=i+1;j<n;j++)
        {
            if (!used[j]&&!strcmp(arr[i],arr[j]))
            used[j]=1;
        }
    }
    
}printf("%d",sort);
free(used);
return 0;
}
