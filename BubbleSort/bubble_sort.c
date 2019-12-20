#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j+1);
            }
        }
    }
}

void bubble_sort_quicker(int arr[], int n) {
    int i, j, flag;
    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j+1);
                flag = 1;
            }
        }
        if (!flag) return;
    }
}

int main() {
    int arr[] = {7, 2, 5, 3, 8};
    int n = sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, n);
    // bubble_sort_quicker(arr, n);
    printf("Sort result:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
