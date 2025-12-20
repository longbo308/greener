#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void swap(int v[],int i,int j){
    int temp;
    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}
void qsort1 (int v[],int left,int right){
    int i,last;
    void swap(int v[],int i,int j);
    if (left>=right)
    return;
    swap(v,left,(left+right)/2);
    last=left;
    for (i=left+1;i<=right;i++)
        if (v[i]<v[left])
        swap(v,++last,i);
    swap(v,left,last);
    qsort1(v,left,last-1);
    qsort1(v,last+1,right);
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int*arr=(int*)calloc(n,sizeof(int));
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    qsort1(arr,0,n-1);
    printf("%d",*(arr+k));
    free(arr);
    return 0;
}