#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    char arr[6][100];
    int n[6] = {0};  // 明确大小为6，并初始化
    int k = 0;
    
    // 修正字典数据 - 确保di数组与dic数组对应
    char dic[30][20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", 
                        "eight", "nine", "ten", "eleven", "twelve", "thirteen", 
                        "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", 
                        "nineteen", "twenty", "a", "both", "another", "first", 
                        "second", "third"};
    int di[30] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 0, 21, 44, 69, 96, 25, 56, 
                  89, 24, 61, 0, 1, 4, 1, 1, 4, 9};

    // 读取6个单词
    for (int i = 0; i < 6; i++) {
        scanf("%s", arr[i]);
        
        // 在字典中查找匹配的单词
        int found = 0;
        for (int j = 0; j < 27; j++) {  // 字典有27个条目
            if (strcmp(dic[j], arr[i]) == 0) {  // strcmp返回0表示相等
                n[k++] = di[j];
                found = 1;
                break;
            }
        }
        
        // 如果没有找到匹配的单词，对应位置设为0
        if (!found) {
            n[k++] = 0;
        }
    }

    // 计算实际有效的数字个数
    int valid_count = k;
    
    // 检查是否所有数字都是0
    int all_zero = 1;
    for (int i = 0; i < valid_count; i++) {
        if (n[i] != 0) {
            all_zero = 0;
            break;
        }
    }
    
    if (all_zero) {
        printf("0");
        return 0;
    }
    
    // 排序数字
    bubble(n, valid_count);
    
    // 输出结果，跳过前导0
    int start_index = 0;
    while (start_index < valid_count && n[start_index] == 0) {
        start_index++;
    }
    
    // 输出第一个数字（不带前导0）
    if (start_index < valid_count) {
        printf("%d", n[start_index]);
    }
    
    // 输出剩余数字（保持两位数格式）
    for (int i = start_index + 1; i < valid_count; i++) {
        printf("%02d", n[i]);  // 确保输出两位数
    }
    
    return 0;
}