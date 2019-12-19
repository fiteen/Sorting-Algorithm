#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selection_sort(int arr[], int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        int min = i;
        for (j = i + 1; j < len; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr, min, i);
    }
}

int main() {
    int arr[] = {7, 2, 5, 3, 6};
    int n = sizeof(arr) / sizeof(*arr);
    selection_sort(arr, n);
    printf("Sort result:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
