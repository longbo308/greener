#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool is_prime(int n){
    if (n<=1)return false;
    if (n==2)return true;
    if (n%2==0)return false;
    for (int i=3;i*i<=n;i=i+2){
        if (n%i==0)return false;
    }
    return true;
}
int main(){
    int n;
    scanf("%d",&n);
    int i;int other;
    for (i=2;i*i<=n;i++){
        if (n%i==0){
            other=n/i;
            if (is_prime(i)&&is_prime(other)){
                printf("%d",i>other?i:other);
                break;
            }
        }
    }
    if (i*i>n) printf("0");
    return 0;
}