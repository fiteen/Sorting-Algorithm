#include <stdio.h>

void insertion_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > temp; j--)
            arr[j] = arr[j - 1];
        arr[j] = temp;
    }
}

int main() {
    int arr[] = {5, 1, 8, 5, 6, 3};
    int n = sizeof(arr) / sizeof(*arr);
    insertion_sort(arr, n);
    printf("Sort result:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
