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

int main() {
    int arr[] = {2, 4, 3, 1, 4, 6, 4, 2};
    int n = sizeof(arr) / sizeof(*arr);
    counting_sort(arr, n);
    printf("Sort result:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
