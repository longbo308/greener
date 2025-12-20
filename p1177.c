#include <stdlib.h>
#include <stdio.h>
int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
int main(){
    int n;
    scanf("%d",&n);
    int*arr=(int*)malloc(n*sizeof(int));
    if (arr=NULL){
        return -1;
    }
    for (int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    qsort(arr,n,sizeof(int),cmp);
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}