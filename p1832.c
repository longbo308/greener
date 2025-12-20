#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);
    if (n < 2) {
        printf("0\n");
        return 0;
    }
    // 筛法求素数
    char* prime = (char*)malloc((n + 1) * sizeof(char));
    memset(prime, 1, (n + 1) * sizeof(char));
    prime[0] = prime[1] = 0;
    
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
    // 动态规划
    long long* dp = (long long*)calloc(n + 1, sizeof(long long));
    dp[0] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            for (int j = i; j <= n; j++) {
                dp[j] += dp[j - i];
            }
        }
    }
    printf("%lld\n", dp[n]);
    free(prime);
    free(dp);
    return 0;
}