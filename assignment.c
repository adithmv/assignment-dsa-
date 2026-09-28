#include <stdio.h>

int comparisons = 0;
int swaps = 0;

void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i > 0) printf(", ");
        printf("%d", arr[i]);
    }
    printf("]");
}

void swap(int arr[], int i, int j) {
    if (i != j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        swaps++;
    }
}

void insert(int heap[], int *size, int value) {
    int i = *size;
    heap[i] = value;
    (*size)++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        comparisons++;
        if (heap[parent] >= heap[i]) break;
        swap(heap, parent, i);
        i = parent;
    }
}

void heapify(int arr[], int size, int root) {
    while (1) {
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        if (left < size) {
            comparisons++;
            if (arr[left] > arr[largest]) largest = left;
        }
        if (right < size) {
            comparisons++;
            if (arr[right] > arr[largest]) largest = right;
        }
        if (largest == root) break;
        swap(arr, root, largest);
        root = largest;
    }
}

void heap_sort(int arr[], int size) {
    for (int root = size / 2 - 1; root >= 0; root--) {
        heapify(arr, size, root);
        printf("Build at index %d: ", root);
        print_array(arr, size);
        printf("\n");
    }
    printf("Heap building: %d comparisons, %d swaps\n", comparisons, swaps);
    for (int end = size - 1; end > 0; end--) {
        swap(arr, 0, end);
        heapify(arr, end, 0);
        printf("Heap: ");
        print_array(arr, end);
        printf(" | Sorted: ");
        print_array(arr + end, size - end);
        printf("\n");
    }
}

void quick_sort(int arr[], int low, int high, int size) {
    if (low >= high) return;
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, high);
    printf("Range %d to %d, pivot %d, position %d: ", low, high, pivot, i);
    print_array(arr, size);
    printf("\n");
    quick_sort(arr, low, i - 1, size);
    quick_sort(arr, i + 1, high, size);
}

int main(void) {
    int scores[] = {45, 72, 30, 90, 65, 50, 85};
    int heap[7], heap_values[7], quick_values[7];
    int size = 7;
    int heap_size = 0;
    for (int i = 0; i < size; i++) {
        heap_values[i] = scores[i];
        quick_values[i] = scores[i];
    }
    printf("Patient severity scores: ");
    print_array(scores, size);
    printf("\n\nA) Max Heap Insertion\n");
    for (int i = 0; i < size; i++) {
        insert(heap, &heap_size, scores[i]);
        printf("Insert %d: ", scores[i]);
        print_array(heap, heap_size);
        printf("\n");
    }
    printf("Comparisons: %d, Swaps: %d\n", comparisons, swaps);
    printf("Highest-priority patient: %d\n", heap[0]);

    comparisons = 0;
    swaps = 0;
    printf("\nB) Heap Sort\n");
    heap_sort(heap_values, size);
    printf("Comparisons: %d, Swaps: %d\n", comparisons, swaps);
    printf("Final output: ");
    print_array(heap_values, size);
    printf("\n");

    comparisons = 0;
    swaps = 0;
    printf("\nB) Quick Sort\n");
    quick_sort(quick_values, 0, size - 1, size);
    printf("Comparisons: %d, Swaps: %d\n", comparisons, swaps);
    printf("Final output: ");
    print_array(quick_values, size);
    printf("\n");
    return 0;
}
