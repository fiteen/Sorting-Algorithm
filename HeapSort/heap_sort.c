#include <stdio.h>

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void Heapify(int tree[], int n, int i) {
	// n 表示序列长度，i 表示父节点下标
	if (i >= n) return;
	// 左侧子节点下标
	int left = 2 * i + 1;
	// 右侧子节点下标
	int right = 2 * i + 2;
	int max = i;
	if (left < n && tree[left] > tree[max]){
		max = left;
	}
	if (right < n && tree[right] > tree[max]){
		max = right;
	}
	if (max != i) {
		swap(tree, max, i);
		Heapify(tree, n, max);
	}
}

void BuildHeap(int tree[], int n) {
	// 树最后一个节点的下标
	int last_node = n - 1;
	// 最后一个节点对应的父节点下标
	int parent = (last_node - 1) / 2;
	int i;
	for (i = parent; i >= 0; i--) {
		Heapify(tree, n, i);
	}
}

void HeapSort(int tree[], int n) {
	BuildHeap(tree, n);
	int i;
	for (i = n - 1; i >= 0; i--) {
		// 将堆顶元素与最后一个元素交换
		swap(tree, i, 0);
		// 调整成大顶堆
		Heapify(tree, i, 0);
	}
}

int main() {
    int arr[] = {5, 2, 7, 3, 6, 1, 4};
    int n = sizeof(arr) / sizeof(*arr);
    HeapSort(arr, n);
    printf("Sort result:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
