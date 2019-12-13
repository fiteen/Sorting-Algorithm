#include <stdio.h>

void bubble_sort(int arr[], int len) {
    int i, j, tmp;
    for (i = 0; i < len - 1; i++) {  
        for (j = 0; j < len - i - 1; j++) {  
            if (arr[j] > arr[j + 1]) {  
                tmp = arr[j];  
                arr[j] = arr[j + 1];  
                arr[j + 1] = tmp;  
            }
        }  
    }  
}

int main() {
	int arr[] = { 7, 2, 5, 3, 8};
	int len = sizeof(arr) / sizeof(*arr);
	bubble_sort(arr, len);
	int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
	return 0;
}
