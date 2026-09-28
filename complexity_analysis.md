# Complexity Analysis

Let n be the number of patients. The seven given scores are one example; the bounds below describe growth as n increases.

| Operation or algorithm | Best time | Average time | Worst time | Auxiliary space |
| --- | --- | --- | --- | --- |
| Insert one patient into a Max Heap | O(1) | O(log n) upper bound | O(log n) | O(1) |
| Read highest severity from Max Heap | O(1) | O(1) | O(1) | O(1) |
| Remove highest severity from Max Heap | O(1) | O(log n) upper bound | O(log n) | O(1) with iterative heapify |
| Build heap by repeated insertion | O(n) | O(n log n) upper bound | O(n log n) | O(1) beyond heap storage |
| Build heap from bottom up | O(n) | O(n) | O(n) | O(1) |
| Heap Sort, distinct scores | O(n log n) | O(n log n) | O(n log n) | O(1) |
| Quick Sort | O(n log n) | O(n log n) | O(n^2) | O(log n) best/average, O(n) worst |

## Heap structure

A Max Heap is a complete binary tree stored in an array. The children of index i are at 2i + 1 and 2i + 2. Its height is floor(log2(n)), so seven nodes have height 2 and occupy three levels. Every parent has a score at least as large as its children.

Insertion moves a score upward along at most one root-to-leaf path. Removing the maximum replaces the root with the final element and moves that value downward. Reading the maximum only accesses the root. The program demonstrates insertion and reading the root; removal is included here to explain the hospital use case.

## Sorting time

Heap Sort builds its heap in O(n). It then removes the maximum n - 1 times, with each heap restoration taking at most O(log n).

Quick Sort partitions a range in linear time. Balanced partitions give O(log n) levels and O(n log n) total work. Highly uneven partitions give O(n) levels and O(n^2) work. With the last-element pivot used here, already sorted data is a worst case. The average bound assumes random input order.

## Space and trace printing

The heap needs O(n) storage for patients. Iterative heapify uses constant extra space. Quick Sort uses a recursive call stack.

The demonstration keeps separate arrays for the original scores, heap insertion, and the two sorts. This takes O(n) storage when generalized. The actual C arrays have capacity seven. Supporting further arrivals would require capacity management.

The standard sorting bounds exclude trace printing. Printing a full array after each important step adds O(n^2) output work to this demonstration for both sorts in the worst case. Printing the heap after every insertion also adds O(n^2) output work. Printing does not copy the arrays.
