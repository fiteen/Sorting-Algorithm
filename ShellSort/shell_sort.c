#include <stdio.h>

void ShellSort_SplitHalf(int arr[], int len) {
	int i, j, dk, temp;
	for (dk = len >> 1; dk > 0; dk = dk >> 1) {
		for (i = dk; i < len; i++) {
			temp = arr[i];
			for (j = i - dk; j >= 0 && arr[j] > temp; j -= dk)
				arr[j + dk] = arr[j];
			arr[j + dk] = temp;
		}
	}
}

void ShellInsert(int arr[], int len, int dk) {
	int i, j, temp;
	for (i = dk; i < len; i+= dk) {
		temp = arr[i];
		j = i - dk;
		while (j >= 0 && temp < arr[j]) {
			arr[j+dk] = arr[j];
			j -= dk;
		}
		arr[j+dk] = temp;
	}
}

void ShellSort(int arr[], int len, int dlta[], int t) {
	int k;
	for (k = 0; k < t; ++k) {
		// 一趟增量为 dlta[k] 的插入排序
		ShellInsert(arr, len, dlta[k]);
	}
}

int main() {
    int arr[] = {5, 4, 7, 9, 8, 2, 3, 5, 6, 1};
    int len = sizeof(arr) / sizeof(*arr);
    int dlta[] = {5, 3, 1};
    int t = sizeof(dlta) / sizeof(*dlta);
    // ShellSort_SplitHalf(arr, len);
    ShellSort(arr, len, dlta, t);
    printf("Sort result:\n");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}
