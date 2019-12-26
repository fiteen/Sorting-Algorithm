#include <stdio.h>
#include <string.h>

void bucket_sort(int arr[], int n, int bucket_count) {
    if (arr == NULL || bucket_count < 1) return;

    // 根据最大/最小元素和桶数量，计算出每个桶对应的元素范围
    int max = arr[0], min = arr[0];
    int i, j;
    for (i = 1; i < n; i++) {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }
    int range = (max - min + 1) / bucket_count + 1;

    // 建立桶对应的二维数组，一个桶里最多可能出现 n 个元素
    int buckets[bucket_count][n];
    memset(buckets, 0, sizeof(buckets));
    int counts[bucket_count];
    memset(counts, 0, sizeof(counts));
    for (i = 0; i < n; i++) {
        int k = (arr[i] - min) / range;
        buckets[k][counts[k]++] = arr[i];
    }

    int index = 0;
    for (i = 0; i < bucket_count; i++) {
        // 分别对每个非空桶内数据进行排序，比如计数排序
        if (buckets[i][0] == 0) continue;
        counting_sort(buckets[i], n);
        // 拼接非空的桶内数据，得到最终的结果
        for (j = 0; j < n; j++) {
            if (buckets[i][j] != 0) {
                arr[index++] = buckets[i][j];
            }
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
