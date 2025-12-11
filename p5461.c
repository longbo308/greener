#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int power_2(int n){
    return 1<<n;
}
void f(int**a,int n,int x,int y){
    if (n==0) return ;
    int len=power_2(n);
    for (int i=x;i<x+len/2;i++){
        for (int j=y;j<y+len/2;j++){
            a[i][j]=0;
        }
    }
     f(a,n-1,x,y+len/2);
     f(a,n-1,x+len/2,y);
     f(a,n-1,x+len/2,y+len/2);
}
int main(){
    int n;
    scanf("%d",&n);
    int**arr=calloc(power_2(n),sizeof(int*));
    for (int i=0;i<power_2(n);i++){
        arr[i]=calloc(power_2(n),sizeof(int));
    }
    for (int i=0;i<power_2(n);i++){
        for (int j=0;j<power_2(n);j++){
            arr[i][j]=1;
        }
    }
    f(arr,n,0,0);
    for (int i=0;i<power_2(n);i++){
        for (int j=0;j<power_2(n);j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    for (int i=0;i<power_2(n);i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}