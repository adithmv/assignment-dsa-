# Trace Tables

## Max Heap insertion

Each new score is added at the end of the heap. It is then swapped with its parent until the parent is greater than or equal to it.

| Inserted score | Heap in array form |
| --- | --- |
| 45 | [45] |
| 72 | [72, 45] |
| 30 | [72, 45, 30] |
| 90 | [90, 72, 30, 45] |
| 65 | [90, 72, 30, 45, 65] |
| 50 | [90, 72, 50, 45, 65, 30] |
| 85 | [90, 72, 85, 45, 65, 30, 50] |

The final heap is:

```text
        90
      /    \
    72      85
   /  \    /  \
 45   65  30   50
```

It is a complete binary tree. Every parent is greater than or equal to its children. It has 7 nodes, 3 levels and height 2, counting edges from the root to the deepest leaf. In general, its height is floor(log2(n)). The highest-priority patient has severity 90 and is at the root.

The insertions required **9 comparisons and 5 swaps**.

## b) Sorting

Both sorting functions start with the original scores and produce ascending order.

### Heap Sort

First, build a max heap from the last non-leaf node towards the root:

| Heapify root index | Array after heapify |
| --- | --- |
| 2 | [45, 72, 85, 90, 65, 50, 30] |
| 1 | [45, 90, 85, 72, 65, 50, 30] |
| 0 | [90, 72, 85, 45, 65, 50, 30] |

This heap differs from the insertion heap because it was built from the bottom up. Both satisfy the max heap property. Building this heap took 8 comparisons and 4 swaps.

Next, swap the root with the last element of the active heap, reduce the heap size, and restore the heap property:

| Step | Active heap | Sorted part |
| --- | --- | --- |
| 1 | [85, 72, 50, 45, 65, 30] | [90] |
| 2 | [72, 65, 50, 45, 30] | [85, 90] |
| 3 | [65, 45, 50, 30] | [72, 85, 90] |
| 4 | [50, 45, 30] | [65, 72, 85, 90] |
| 5 | [45, 30] | [50, 65, 72, 85, 90] |
| 6 | [30] | [45, 50, 65, 72, 85, 90] |

Final output: **[30, 45, 50, 65, 72, 85, 90]**

Total, including heap building: **21 comparisons and 18 swaps**.

### Quick Sort

The last element of each range is chosen as the pivot. Lomuto partitioning places values less than or equal to the pivot on its left and greater values on its right. The two sides are then sorted recursively. Indices start at 0.

| Range | Pivot | Final pivot index | Array after partition |
| --- | --- | --- | --- |
| 0 to 6 | 85 | 5 | [45, 72, 30, 65, 50, 85, 90] |
| 0 to 4 | 50 | 2 | [45, 30, 50, 65, 72, 85, 90] |
| 0 to 1 | 30 | 0 | [30, 45, 50, 65, 72, 85, 90] |
| 3 to 4 | 72 | 4 | [30, 45, 50, 65, 72, 85, 90] |

Final output: **[30, 45, 50, 65, 72, 85, 90]**

Total: **12 comparisons and 6 swaps**.
