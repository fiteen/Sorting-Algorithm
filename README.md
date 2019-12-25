# 经典排序算法动画与解析

排序算法是程序员必备的基础知识，弄明白它们的原理和实现很有必要。

我们可以将常见的排序算法可以分成两类：

![](sort-category.png)

**比较类排序**：通过比较来决定元素间的相对次序，时间复杂度为 O(nlogn)～O(n²)。属于比较类的有：

|         排序算法          | 时间复杂度 | 最差情况 | 最好情况 | 空间复杂度 | 稳定性 | 排序方式  |
| :-----------------------: | :--------: | :------: | :------: | :--------: | :----: | :-------: |
|  [冒泡排序](BubbleSort)   |   O(n²)    |  O(n²)   |   O(n)   |    O(1)​    |  稳定  | In-place  |
|   [快速排序](QuickSort)   |  O(nlogn)​  |  O(n²)   | O(nlogn)​ |  O(logn)​   | 不稳定 | In-place  |
| [插入排序](InsertionSort) |   O(n²)    |  O(n²)   |   O(n)​   |    O(1)​    |  稳定  | In-place  |
|   [希尔排序](ShellSort)   |  O(nlog²n)​  |  O(n²)   |   O(n)​   |    O(1)​    | 不稳定 | In-place  |
| [选择排序](SelectionSort) |   O(n²)    |  O(n²)   |  O(n²)   |    O(1)​    | 不稳定 | In-place  |
|    [堆排序](HeapSort)     |  O(nlogn)​  | O(nlogn) | O(nlogn)​ |    O(1)​    | 不稳定 | In-place  |
|   [归并排序](MergeSort)   |  O(nlogn)​  | O(nlogn) | O(nlogn)​ |    O(n)​    |  稳定  | Out-place |

**非比较类排序**：不通过比较来决定元素间的相对次序，其时间复杂度可以突破 O(nlogn)，以线性时间运行。属于非比较类的有：

|         排序算法         | 时间复杂度 | 最差情况 | 最好情况 | 空间复杂度 | 稳定性 | 排序方式  |
| :----------------------: | :--------: | :------: | :------: | :--------: | :----: | :-------: |
| [计数排序](CountingSort) |   O(n+k)​   |  O(n+k)​  |  O(n+k)​  |   O(n+k)​   |  稳定  | Out-place |
|   [桶排序](BubbleSort)   |   O(n+k)​   |  O(n²)   |   O(n)​   |   O(n+k)​   |  稳定  | Out-place |
|         基数排序         |   O(n×k)​   |  O(n×k)​  |  O(n×k)​  |   O(n+k)​   |  稳定  | Out-place |


**n**：待排序列的个数

**In-place**：原地算法，指的是占用常用内存，不占用额外内存。空间复杂度为 O(1) 的都可以认为是原地算法

**Out-place**：非原地算法，占用额外内存

**稳定性**：假设待排序列中两元素相等，排序前后这两个相等元素的相对位置不变，则认为是稳定的。