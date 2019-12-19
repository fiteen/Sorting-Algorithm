#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j, tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp; 
            }
        }
    }
}

void bubble_sort_quicker(int arr[], int n) {
    int i, j, tmp, flag;
    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 1;
            }
        }
        if (!flag) return;
    }
}

int main() {
    int arr[] = { 7, 2, 5, 3, 8};
    int n = sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, n);
    // bubble_sort_quicker(arr, n);
    printf("Sort result:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
