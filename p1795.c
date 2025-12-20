#include <stdio.h>
#include <stdlib.h>

int istriangular(long long int n)
{
    if (n < 0) return 0;  
    int sum = 0;
    int k = 1;
    long long int m=n-1;
    while (sum < m)
    {
        sum += k;
        k++;
    }
    return sum == m;  
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