#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define MAXN 205
#define MAXS 10

char str[MAXN];
char words[MAXS][MAXN];
int p, k, s, n;
int dp[MAXN][MAXN];
bool used[MAXN];

int query(int l, int r) {
    int res = 0;
    // 重置used数组
    for (int i = l; i <= r; i++) 
        used[i] = false;
    
    // 尝试每个起始位置
    for (int start = l; start <= r; start++) {
        if (used[start]) continue;
        
        // 尝试匹配每个单词
        for (int w = 1; w <= s; w++) {
            int word_len = strlen(words[w] + 1);  // 单词长度（从1开始存储）
            
            // 检查是否超出右边界
            if (start + word_len - 1 > r) 
                continue;
            
            bool match = true;
            // 检查是否匹配这个单词
            for (int j = 1; j <= word_len; j++) {
                if (words[w][j] != str[start + j - 1]) {
                    match = false;
                    break;
                }
            }
            
            // 如果匹配成功
            if (match) {
                res++;
                used[start] = true;  // 标记这个起始位置已使用
                break;  // 匹配到一个单词后就可以跳出单词循环
            }
        }
    }
    return res;
}

int main() {
    scanf("%d %d", &p, &k);  // p为行数，k表示字符串分为k个部分
    n = 0;
    
    // 读取p行，每行20个字符
    for (int i = 1; i <= p; i++) {
        char line[25];
        scanf("%s", line);
        for (int j = 0; j < 20; j++) {
            str[++n] = line[j];
        }
    }
    
    scanf("%d", &s);
    for (int i = 1; i <= s; i++) {
        scanf("%s", words[i] + 1);  // 从下标1开始存储
    }
    
    // 预处理word_cnt[l][r]
    int word_cnt[MAXN][MAXN] = {0};
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            word_cnt[l][r] = query(l, r);
        }
    }
    
    // 动态规划初始化
    for (int i = 1; i <= n; i++) {
        dp[i][1] = word_cnt[1][i];
    }
    
    // 动态规划递推
    for (int j = 2; j <= k; j++) {
        for (int i = j; i <= n; i++) {
            dp[i][j] = 0;
            for (int l = j - 1; l < i; l++) {
                int val = dp[l][j - 1] + word_cnt[l + 1][i];
                if (val > dp[i][j]) {
                    dp[i][j] = val;
                }
            }
        }
    }
    
    printf("%d\n", dp[n][k]);
    return 0;
}