# Final Conclusion

For the given scores, Heap Sort used 21 comparisons and 18 swaps, while Quick Sort used 12 comparisons and 6 swaps. Both produced [30, 45, 50, 65, 72, 85, 90].


A **Max Heap priority queue** is the best choice for continuously arriving patients. Inserting a patient takes O(log n), the highest severity is immediately available at the root in O(1), and removing that patient takes O(log n).

Heap Sort and Quick Sort are useful when the hospital needs a fully sorted list. Re-sorting after every arrival does unnecessary work. Maintaining the max heap directly gives the hospital the operations it needs efficiently.
