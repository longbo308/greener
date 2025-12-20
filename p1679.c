#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 0x3f3f3f3f  // 修正：完整的32位INF
#define min(a, b) ((a) < (b) ? (a) : (b))

int f(int m) {
    if (m <= 0) return 0;
    
    // 计算最大底数
    int max_num = 1;
    while ((max_num + 1) * (max_num + 1) * (max_num + 1) * (max_num + 1) <= m) {
        max_num++;
    }
    
    // 创建dp数组
    int* dp = (int*)malloc((m + 1) * sizeof(int));
    
    // 初始化：不能用memset设置非0/-1的值
    for (int i = 0; i <= m; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;  // 凑出0需要0个数
    
    // 完全背包DP：外层循环物品，内层循环容量（正序）
    for (int j = 1; j <= max_num; j++) {
        int weight = j * j * j * j;  // 直接计算，避免pow
        
        for (int i = weight; i <= m; i++) {  // 正序遍历
            if (dp[i - weight] != INF) {  // 确保可达
                dp[i] = min(dp[i], dp[i - weight] + 1);
            }
        }
    }
    
    int result = dp[m];
    free(dp);
    return result;
}

int main() {
    int m;
    scanf("%d", &m);
    printf("%d\n", f(m));
    return 0;
}