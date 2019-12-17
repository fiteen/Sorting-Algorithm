#include <stdio.h>

void StraightInsertionSort(int arr[], int len) {
	int i, j, temp;
	for (i = 1; i < len; i++) {
		temp = arr[i];
		for (j = i; j > 0 && arr[j-1] > temp; j--)
			arr[j] = arr[j-1];
		arr[j] = temp;
	}
}

int main() {
    int arr[] = { 5, 1, 8, 5, 6, 3};
    int len = sizeof(arr) / sizeof(*arr);
    StraightInsertionSort(arr, len);
    printf("Sort result:\n");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}
