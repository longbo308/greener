#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    printf("1\n");
    
    for (int i=1;i<n;i++){
        long long int an=1;
        for (int j=0;j<=i;j++){
            printf("%lld ",an);
            an=an*(i-j)/(j+1);
        }
        printf("\n");
    }
}