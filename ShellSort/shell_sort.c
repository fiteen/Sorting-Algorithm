#include <stdio.h>

void shell_sort_split_half(int arr[], int n) {
    int i, j, dk, temp;
    for (dk = n >> 1; dk > 0; dk = dk >> 1) {
        for (i = dk; i < n; i++) {
            temp = arr[i];
            for (j = i - dk; j >= 0 && arr[j] > temp; j -= dk)
                arr[j + dk] = arr[j];
            arr[j + dk] = temp;
		}
	}
}

void shell_insert(int arr[], int n, int dk) {
    int i, j, temp;
    for (i = dk; i < n; i+= dk) {
        temp = arr[i];
        j = i - dk;
        while (j >= 0 && temp < arr[j]) {
            arr[j+dk] = arr[j];
            j -= dk;
        }
        arr[j+dk] = temp;
    }
}

void shell_sort(int arr[], int n, int dlta[], int t) {
    int k;
    for (k = 0; k < t; ++k) {
        // 一趟增量为 dlta[k] 的插入排序
        shell_insert(arr, n, dlta[k]);
    }
}

int main() {
    int arr[] = {5, 4, 7, 9, 8, 2, 3, 5, 6, 1};
    int n = sizeof(arr) / sizeof(*arr);
    int dlta[] = {5, 3, 1};
    int t = sizeof(dlta) / sizeof(*dlta);
    // shell_sort_split_half(arr, n);
    shell_sort(arr, n, dlta, t);
    printf("Sort result:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
