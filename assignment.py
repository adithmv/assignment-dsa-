scores = [45, 72, 30, 90, 65, 50, 85]


class MaxHeap:
    def __init__(self):
        self.heap = []
        self.comparisons = 0
        self.swaps = 0

    def insert(self, value):
        self.heap.append(value)
        i = len(self.heap) - 1
        while i > 0:
            parent = (i - 1) // 2
            self.comparisons += 1
            if self.heap[parent] >= self.heap[i]:
                break
            self.heap[parent], self.heap[i] = self.heap[i], self.heap[parent]
            self.swaps += 1
            i = parent

    def highest_priority(self):
        return self.heap[0] if self.heap else None


def heap_sort(values):
    arr = values.copy()
    comparisons = 0
    swaps = 0

    def heapify(size, root):
        nonlocal comparisons, swaps
        while True:
            largest = root
            left = 2 * root + 1
            right = 2 * root + 2
            if left < size:
                comparisons += 1
                if arr[left] > arr[largest]:
                    largest = left
            if right < size:
                comparisons += 1
                if arr[right] > arr[largest]:
                    largest = right
            if largest == root:
                break
            arr[root], arr[largest] = arr[largest], arr[root]
            swaps += 1
            root = largest

    for root in range(len(arr) // 2 - 1, -1, -1):
        heapify(len(arr), root)
        print(f"Build at index {root}: {arr}")

    print(f"Heap building: {comparisons} comparisons, {swaps} swaps")
    for end in range(len(arr) - 1, 0, -1):
        arr[0], arr[end] = arr[end], arr[0]
        swaps += 1
        heapify(end, 0)
        print(f"Heap: {arr[:end]} | Sorted: {arr[end:]}")

    print(f"Comparisons: {comparisons}, Swaps: {swaps}")
    return arr


def quick_sort(values):
    arr = values.copy()
    comparisons = 0
    swaps = 0

    def swap(i, j):
        nonlocal swaps
        if i != j:
            arr[i], arr[j] = arr[j], arr[i]
            swaps += 1

    def sort(low, high):
        nonlocal comparisons
        if low >= high:
            return
        pivot = arr[high]
        i = low
        for j in range(low, high):
            comparisons += 1
            if arr[j] <= pivot:
                swap(i, j)
                i += 1
        swap(i, high)
        print(f"Range {low} to {high}, pivot {pivot}, position {i}: {arr}")
        sort(low, i - 1)
        sort(i + 1, high)

    sort(0, len(arr) - 1)
    print(f"Comparisons: {comparisons}, Swaps: {swaps}")
    return arr


def main():
    print("Patient severity scores:", scores)
    print("\nA) Max Heap Insertion")
    heap = MaxHeap()
    for score in scores:
        heap.insert(score)
        print(f"Insert {score}: {heap.heap}")
    print(f"Comparisons: {heap.comparisons}, Swaps: {heap.swaps}")
    print("Highest-priority patient:", heap.highest_priority())
    print("\nB) Heap Sort")
    print("Final output:", heap_sort(scores))
    print("\nB) Quick Sort")
    print("Final output:", quick_sort(scores))


if __name__ == "__main__":
    main()
