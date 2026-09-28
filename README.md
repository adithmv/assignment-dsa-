# Hospital Patient Priority Queue

Severity scores: `45, 72, 30, 90, 65, 50, 85`

A higher score means a patient has higher priority. The solution is written in Python without code comments.

## Run the program

```text
python assignment.py
```

The program runs all three parts and prints the intermediate steps. The actual execution output is saved in [output.txt](output.txt).

## a) Max Heap insertion

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

```text
Index 2: [45, 72, 85, 90, 65, 50, 30]
Index 1: [45, 90, 85, 72, 65, 50, 30]
Index 0: [90, 72, 85, 45, 65, 50, 30]
```

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

## c) Analysis

Only comparisons between severity scores are counted. Loop conditions and index checks are excluded. A swap exchanges two different array positions; swapping an element with itself is skipped. Counts depend on the input and the chosen implementation.

| Property | Max Heap priority queue | Heap Sort | Quick Sort |
| --- | --- | --- | --- |
| Structure | Complete binary tree stored as an array | Uses a shrinking max heap | Partitions an array around pivots; no heap |
| Height | 2 for these 7 scores; O(log n) generally | Initial heap height 2; decreases as elements are removed | No heap height; recursion depth averages O(log n), worst O(n) |
| Observed comparisons | 9 for all insertions | 21 including heap building | 12 |
| Observed swaps | 5 for all insertions | 18 including heap building | 6 |
| Time | Insert O(log n) worst case; read maximum O(1); remove maximum O(log n) | O(n log n) best, average and worst for distinct scores; bottom-up build O(n) | Best/average O(n log n), worst O(n^2) |
| Algorithm space | O(n) to store patients; O(1) extra per insertion | O(1) auxiliary space with iterative heapify | O(log n) average recursion space, O(n) worst |

Inserting all n scores one at a time takes O(n log n) in the worst case. A bottom-up heap build takes O(n).

The sorting functions copy the input to keep each run independent, so the supplied program uses O(n) extra space for each copy. Printed Heap Sort steps also create temporary slices of up to O(n) size. The space row above describes the sorting algorithms themselves, excluding these copies and display steps.

Quick Sort used fewer comparisons and swaps for this input. That does not guarantee it will always perform better. Choosing the last element as pivot can cause O(n^2) time on already sorted input.

### Suitable approach for the hospital

A **Max Heap priority queue** is the best choice for continuously arriving patients. Inserting a patient takes O(log n), the highest severity is immediately available at the root in O(1), and removing that patient takes O(log n).

Heap Sort and Quick Sort are useful when the hospital needs a fully sorted list. Re-sorting after every arrival does unnecessary work. Maintaining the max heap directly gives the hospital the operations it needs efficiently.
