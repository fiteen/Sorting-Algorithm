#include <stdio.h>
#include <string.h>

void counting_sort(int arr[], int n) {
    if (arr == NULL) return;
    // 定义辅助空间并初始化
    int max = arr[0], min = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }
    int r = max - min + 1;
    int C[r];
    memset(C, 0, sizeof(C));
    // 定义目标数组
    int R[n];
    // 统计每个元素出现的次数
    for (i = 0; i < n; i++) C[arr[i] - min]++;
    // 对辅助空间内数据进行计算
    for (i = 1; i < r; i++) C[i] += C[i - 1];
    // 反向填充目标数组
    for (i = n - 1; i >= 0; i--) R[--C[arr[i] - min]] = arr[i];
    // 目标数组里的结果重新赋值给 arr
    for (i = 0; i < n; i++) arr[i] = R[i];
}

void bucket_sort(int arr[], int n, int r) {
    if (arr == NULL || r < 1) return;

    // 根据最大/最小元素和桶数量，计算出每个桶对应的元素范围
    int max = arr[0], min = arr[0];
    int i, j;
    for (i = 1; i < n; i++) {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }
    int range = (max - min + 1) / r + 1;

    // 建立桶对应的二维数组，一个桶里最多可能出现 n 个元素
    int buckets[r][n];
    memset(buckets, 0, sizeof(buckets));
    int counts[r];
    memset(counts, 0, sizeof(counts));
    for (i = 0; i < n; i++) {
        int k = (arr[i] - min) / range;
        buckets[k][counts[k]++] = arr[i];
    }

    int index = 0;
    for (i = 0; i < r; i++) {
        // 分别对每个非空桶内数据进行排序，比如计数排序
        if (counts[i] == 0) continue;
        counting_sort(buckets[i], counts[i]);
        // 拼接非空的桶内数据，得到最终的结果
        for (j = 0; j < counts[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int arr[] = {28, 36, 8, 32, 41, 45, 37, 2};
    int n = sizeof(arr) / sizeof(*arr);
    bucket_sort(arr, n, 5);
    printf("Sort result:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
