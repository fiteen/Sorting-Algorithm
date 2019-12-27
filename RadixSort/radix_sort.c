#include <stdio.h>
#include <string.h>
#include <math.h>

// 基数，范围0~9
#define RADIX 10

void radix_sort(int arr[], int n) {
    // 获取最大值和最小值
    int max = arr[0], min = arr[0];
    int i, j, l;
    for (i = 1; i < n; i++) {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }
    // 假如序列中有负数，所有数加上一个常数，使序列中所有值变成正数
    if (min < 0) {
        for (i = 0; i < n; i++) arr[i] -= min;
        max -= min;
    }
    // 获取最大值位数
    int d = 0;
    while (max > 0) {
        max /= RADIX;
        d ++;
    }
    int queue[RADIX][n];
    memset(queue, 0, sizeof(queue));
    int count[RADIX] = {0};
    for (i = 0; i < d; i++) {
        // 分配数据
        for (j = 0; j < n; j++) {
            int key = arr[j] % (int)pow(RADIX, i + 1) / (int)pow(RADIX, i);
            queue[key][count[key]++] = arr[j];
        }
        // 收集数据
        int c = 0;
        for (j = 0; j < RADIX; j++) {
            for (l = 0; l < count[j]; l++) {
                arr[c++] = queue[j][l];
                queue[j][l] = 0;
            }
            count[j] = 0;
        }
    }
    // 假如序列中有负数，收集排序结果时再减去前面加上的常数
    if (min < 0) {
        for (i = 0; i < n; i++) arr[i] += min;
    }
}

int main() {
    int arr[] = {35, 10, 43, 3, 52, 21, 86, 19, 63, 60};
    int n = sizeof(arr) / sizeof(*arr);
    radix_sort(arr, n);
    printf("Sort result:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
