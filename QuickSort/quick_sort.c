#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/* 选取序列的第一个元素作为基准 */
int select_pivot(int arr[], int low) {
    return arr[low];
}

/* 随机选择基准的位置，区间在 low 和 high 之间 */
int select_pivot_random(int arr[], int low, int high) {
    srand((unsigned)time(NULL));
    int pivot = rand()%(high - low) + low;
    swap(arr, pivot, low);
	
    return arr[low];
}

/* 取起始位置、中间位置、末尾位置指向的元素三者的中间值作为基准 */
int select_pivot_median_of_three(int arr[], int low, int high) {
    // 计算数组中间的元素的下标
    int mid = low + ((high - low) >> 1);
    // 排序，使 arr[mid] <= arr[low] <= arr[high]
    if (arr[mid] > arr[high]) swap(arr, mid, high);
    if (arr[low] > arr[high]) swap(arr, low, high);
    if (arr[mid] > arr[low]) swap(arr, low, mid);
    // 使用 low 位置的元素作为基准
    return arr[low];
}

void quick_sort(int arr[], int low, int high) {
    int i, j, pivot;
    if (low >= high) return;
    // pivot = select_pivot(arr, low);
    // pivot = select_pivot_random(arr, low, high);
    pivot = select_pivot_median_of_three(arr, low, high);
    i = low;
    j = high;
    while (i != j) {
        while (arr[j] >= pivot && i < j) j--;
        while (arr[i] <= pivot && i < j) i++;
        if (i < j) swap(arr, i, j);
    }
    arr[low] = arr[i];
    arr[i] = pivot;
    quick_sort(arr, low, i - 1);
    quick_sort(arr, i + 1, high);
}

int main() {
    int arr[] = {5, 1, 7, 2, 8, 3, 4, 9, 0, 6};
    int n = sizeof(arr) / sizeof(*arr);
    quick_sort(arr, 0, n - 1);
    printf("Sort result:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
