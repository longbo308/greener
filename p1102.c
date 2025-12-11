#include <stdio.h>
#include <stdlib.h>
void qsort1(int*arr,int left,int right){
    int i,last;
    void swap(int v[],int i,int j);
    if (left>=right)
    return;
    swap(arr,left,(left+right)/2);
    last=left;
    for (i=left+1;i<=right;i++)
    {
        if (arr[i]<arr[left])
        swap(arr,++last,i);

    }
    swap(arr,left,last);
    qsort1(arr,left,last-1);
    qsort1(arr,last+1,right);
}
void swap(int v[],int i,int j){
    int temp;
    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}
int main(){
    int n,c;
    int count=0;
    scanf("%d %d",&n,&c);
    int* arr=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    if (c<0) c=-c;
    qsort1(arr,0,n-1);
    int i=0;int j=1;
    while (j<n)
    {
        int diff=arr[j]-arr[i];
        if (diff==c){
            int leftcount=1,rightcount=1;
            while (i+1<j&&arr[i]==arr[i+1]){
                leftcount++;
                i++;
            }
            while (j+1<n&&arr[j]==arr[j+1]){
                rightcount++;
                j++;
            }
            count+=leftcount*rightcount;
            i++;
            j++;
        }
        else if (diff<c){
            j++;
        }
        else {
            i++;
            if (i==j) j++;
        }
    }
    printf("%d",count);
    free(arr);
    return 0;
}