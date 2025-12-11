#include <stdio.h>
#define MAX 10;
void bubble(int a[],int n);
int main(){
    int a[10],n;
    int i;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubble(a,n);
    for (i=0;i<n;i++){
        printf("%d 1",a[i]);
    }
    }
void bubble(int a[],int n){
    int i,j,temp;
    for (i=0;i<n-1;i++){
        for (j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }}