#include <stdio.h>
#include <stdlib.h>
int is_huihun(int n){
    int rev=0,original=n;
    while (n>0){
        rev=rev*10+n%10;
        n/=10;
    }
    return rev==original;
}
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
    int a,b;
    scanf("%d %d",&a,&b);
    for (int i=a;i<=b;i++){
        if (is_huihun(i)){
            if (is_prime(i)){
                printf("%d\n",i);
            }
        }
    }
}