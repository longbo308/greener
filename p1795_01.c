#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int istriangular(long long int n)
{
    if (n < 0) return 0;
    if (n==0||n==1) return 1;  
    n--;
    long long k=(long long int)((-1+sqrt(1.0+8*n))/2);
    return (k*(k+1)/2==n);
}

int main(){
    long long int n;
    scanf("%lld", &n);
    long long int* arr = (long long int*)calloc(n, sizeof(long long int));
    
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
        if (istriangular(arr[i]))
            printf("1\n");
        else 
            printf("0\n");
    }
    
    free(arr);  
    return 0;
}