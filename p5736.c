#include <stdio.h>
#include <stdlib.h>
int is_prime(int n){
    if (n<=1) return 0;
    if (n==2) return 1;
    if (n%2==0) return 0;
    for (int i=3;i*i<=n;i+=2){
        if (n%i==0) return 0;
    }
    return 1;
}
int main(){
    int n;
    scanf("%d",&n);
    int *arr=malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    int count=0;
    int *arr1=malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        if (is_prime(arr[i])){
            arr1[count++]=arr[i];
        }
    }
    for (int i=0;i<count;i++){
        printf("%d ",arr1[i]);
    }
    free(arr);
    free(arr1);
    return 0;
}