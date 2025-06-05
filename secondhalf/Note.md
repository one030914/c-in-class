## Quick Sort
average case: $O(n \log n)$
> The algorithm selects a pivot. Elements less than the pivot are placed on the left, and those greater are on the right. This process partitions the array recursively until each subarray is indivisible.\
> Each partitioning step takes $O(n)$ time, and the recursion depth is $O(\log n)$, so the total time complexity is $O(n \log n)$.

worst case: $O(n^2)$
> In the worst case, such as when the array is already sorted, if the pivot is always the smallest or largest element, it fails to split the array evenly.\
> Each partitioning step still takes $O(n)$ time, but the recursion depth can be $O(n)$, resulting in a total time complexity is $O(n^2)$.


## Merge Sort
average case and worst case: $O(n \log n)$
> The algorithm that splits the array into halves, recursively sorts each half, and then merges the sorted halves into a single sorted array. Each level of merging takes $O(n)$ time, and the recursion depth is $O(\log n)$, so the total time complexity is $O(n \log n)$.\
> As a result, both the average-case and worst-case time complexity are $O(n \log n)$.

## External Sort
total time complexity: $O(n \log m + \frac{n}{m} \cdot n)$
> External Merge Sort is used when the data set is too large to fit into memory.\
> It splits the data into chunks that fit into memory (size m), sorts each chunk individually, and then merges them together using a multi-way merge.\
> The sorting phase for each chunk takes $O(m \log m)$, resulting in a total of $O(n \log m)$ for all chunks.\
> The merging phase, which combines $\frac{n}{m}$ chunks, has a time complexity of $O(\frac{n}{m} \cdot n)$.\
> Therefore, the total time complexity is: $O(n \log m + \frac{n}{m} \cdot n)$