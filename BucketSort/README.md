## 桶排序

桶排序（Bucket sort）是[计数排序](../CountingSort)的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。

桶排序的工作的原理：假设输入数据服从均匀分布，将数据分到有限数量的桶里，每个桶再分别排序（也有可能是使用别的排序算法或是以递归方式继续用桶排序进行排序）。

### 算法步骤

1. 设置固定数量的空桶；
2. 把数据放在对应的桶内；
3. 分别对每个非空桶内数据进行排序；
4. 拼接非空的桶内数据，得到最终的结果。

### 动图演示

![](bucket-sort.gif)

### 代码实现

#### C语言
```c
void bucket_sort(int arr[], int n, int bucket_count) {
    if (arr == NULL || bucket_count < 1) return;

    // 根据最大/最小元素和桶数量，计算出每个桶对应的元素范围
    int max = arr[0], min = arr[0];
    int i, j;
    for (i = 1; i < n; i++) {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }
    int range = (max - min + 1) / bucket_count + 1;

    // 建立桶对应的二维数组，一个桶里最多可能出现 n 个元素
    int buckets[bucket_count][n];
    memset(buckets, 0, sizeof(buckets));
    int counts[bucket_count];
    memset(counts, 0, sizeof(counts));
    for (i = 0; i < n; i++) {
        int k = (arr[i] - min) / range;
        buckets[k][counts[k]++] = arr[i];
    }

    int index = 0;
    for (i = 0; i < bucket_count; i++) {
        // 分别对每个非空桶内数据进行排序，比如计数排序
        if (counts[i] == 0) continue;
        counting_sort(buckets[i], counts[i]);
        // 拼接非空的桶内数据，得到最终的结果
        for (j = 0; j < counts[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}
```
### 算法分析

桶排序是**稳定排序**，但仅限于桶排序本身，假如桶内排序采用了快速排序之类的非稳定排序，那么就是不稳定的。

#### 时间复杂度

当数据可以均匀分配到每一个桶中，排序效率最高，可以线性时间运行。反之，如果数据被分配到同一个桶中，排序效率最低。桶排序的时间复杂度可以这样看：
- n 次循环，每个数据装入桶
- m 次循环，每个桶中的数据进行排序（每个桶中平均有 n/m 个数据）

假设桶内排序用的是比较先进的排序算法，时间复杂度为 O(nlogn)，那么整个桶排序的时间复杂度为 O(n)+O(m\*(n/m)\*log(n/m))=O(n+nlog(n/m))。k = nlog(n/m)，桶排序的平均时间复杂度为 O(n+k)，最好情况是 O(n)，最差情况是 O(n²)。

#### 空间复杂度

桶排序中，需要创建 m 个桶的额外空间，以及 n 个元素的额外空间，所以桶排序的空间复杂度为 O(n+m)。
