#include <stdio.h>
int gcd(int n,int m){
    return m==0?n:gcd(m,n%m);
}
int lcm(int n,int m){
    return n*m/gcd(n,m);
}//最大公约数和最小公倍数
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int count=0;
    for (int i=a;i<=b;i++){
        for (int j=a;j<+b;j++){
            if (gcd(i,j)==a&&lcm(i,j)==b){
                count++;

            }
        }
    }
    printf("%d\n",count);
    return 0;
}