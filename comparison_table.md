# Comparison Table


Only comparisons between severity scores are counted. Loop conditions and index checks are excluded. A swap exchanges two different array positions; swapping an element with itself is skipped. Counts depend on the input and the chosen implementation.

| Property | Max Heap priority queue | Heap Sort | Quick Sort |
| --- | --- | --- | --- |
| Structure | Complete binary tree stored as an array | Uses a shrinking max heap | Partitions an array around pivots; no heap |
| Height | 2 for these 7 scores; O(log n) generally | Initial heap height 2; decreases as elements are removed | No heap height; recursion depth averages O(log n), worst O(n) |
| Observed comparisons | 9 for all insertions | 21 including heap building | 12 |
| Observed swaps | 5 for all insertions | 18 including heap building | 6 |
| Time | Insert O(log n) worst case; read maximum O(1); remove maximum O(log n) | O(n log n) best, average and worst for distinct scores; bottom-up build O(n) | Best/average O(n log n), worst O(n^2) |
| Algorithm space | O(n) to store patients; O(1) extra per insertion | O(1) auxiliary space with iterative heapify | O(log n) average recursion space, O(n) worst |

Quick Sort used fewer comparisons and swaps on the given data. These are operation counts, not measured execution times. Max Heap insertion does different work from full sorting, so its totals are shown for context rather than as a direct sorting comparison.
