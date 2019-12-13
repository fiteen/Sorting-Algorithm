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

void bubble_sort_quicker(int arr[], int len) {
    int i, j, tmp, flag;
    for (i = 0; i < len - 1; i++) {
        flag = 0;
        for (j = 0; j < len - i - 1; j++) {  
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
    int len = sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, len);
    // bubble_sort_quicker(arr, len);
    printf("sort_result:\n");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}
