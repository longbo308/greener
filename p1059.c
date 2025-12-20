#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int clear(int a[],int n){
    int unique=0;
    qsort(a,n,sizeof(int),cmp);
    for (int i=1;i<n;i++){
        if (a[i]!=a[unique])
        {
            unique++;
            a[unique]=a[i];//双指针去重
        }
    }
    return unique+1;
}
int main(){
    int n;
    scanf("%d",&n);
    int*arr=(int*)calloc(n,sizeof(int));
    for (int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    int size=clear(arr,n);
    printf("%d\n",size);
    for (int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}
