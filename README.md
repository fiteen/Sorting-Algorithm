# 经典排序算法动画与解析

排序算法是程序员必备的基础知识，弄明白它们的原理和实现很有必要。

我们可以将常见的**内部排序算法**可以分成两类：

![](sort-category.png)

**比较类排序**：通过比较来决定元素间的相对次序，时间复杂度为 O(nlogn)～O(n²)。属于比较类的有：

|         排序算法          | 时间复杂度 | 最差情况 | 最好情况 | 空间复杂度 | 排序方式 | 稳定性 |
| :-----------------------: | :--------: | :------: | :------: | :--------: | :----: | :-------: |
|  [冒泡排序](BubbleSort)   |   O(n²)    |  O(n²)   |   O(n)   |    O(1)​    |  In-place  | ✔ |
|   [快速排序](QuickSort)   |  O(nlogn)​  |  O(n²)   | O(nlogn)​ |  O(logn)​   | In-place | ✘ |
| [插入排序](InsertionSort) |   O(n²)    |  O(n²)   |   O(n)​   |    O(1)​    |  In-place  | ✔ |
|   [希尔排序](ShellSort)   |  O(nlog²n)​  |  O(n²)   |   O(n)​   |    O(1)​    | In-place | ✘ |
| [选择排序](SelectionSort) |   O(n²)    |  O(n²)   |  O(n²)   |    O(1)​    | In-place | ✘ |
|    [堆排序](HeapSort)     |  O(nlogn)​  | O(nlogn) | O(nlogn)​ |    O(1)​    | In-place | ✘ |
|   [归并排序](MergeSort)   |  O(nlogn)​  | O(nlogn) | O(nlogn)​ |    O(n)​    |  Out-place  | ✔ |

**非比较类排序**：不通过比较来决定元素间的相对次序，其时间复杂度可以突破 O(nlogn)，以线性时间运行。属于非比较类的有：

|         排序算法         | 时间复杂度 | 最差情况  | 最好情况 | 空间复杂度 | 排序方式 | 稳定性 |
| :----------------------: | :--------: | :-------: | :------: | :--------: | :----: | :-------: |
|   [桶排序](BucketSort)   |   O(n+nlog(n/r))​   |   O(n²)   |   O(n)​   |   O(n+r)​   |  Out-place  | ✔ |
| [计数排序](CountingSort) |   O(n+r)​   |  O(n+r)​   |  O(n+r)​  |   O(n+r)​   |  Out-place  | ✔ |
|  [基数排序](RadixSort)   |  O(d(n+r))​  | O(d(n+r)) |  O(d(n+r))  |   O(n+r)​   |  Out-place  | ✔ |

**名词解释**：

**时间复杂度**：描述一个算法执行时间与数据规模的增长关系

**空间复杂度**：描述一个算法占用空间与数据规模的增长关系

**n**：待排序列的个数

**r**：“桶”的个数（上面的三种非比较类排序都是基于“桶”的思想实现的）

**d**：待排序列的最高位数

**In-place**：原地算法，指的是占用常用内存，不占用额外内存。空间复杂度为 O(1) 的都可以认为是原地算法

**Out-place**：非原地算法，占用额外内存

**稳定性**：假设待排序列中两元素相等，排序前后这两个相等元素的相对位置不变，则认为是稳定的。
