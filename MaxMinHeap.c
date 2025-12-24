#include <stdio.h>

/*
 * TIME COMPLEXITY ANALYSIS:
 * - swap(): O(1) - constant time
 * - maxHeapify()/minHeapify(): O(log n) - height of tree
 *   - May recurse down the height of the heap
 * - buildMaxHeap()/buildMinHeap(): O(n) - builds heap from array
 *   - Despite calling heapify n/2 times, amortized cost is O(n)
 * - printArray(): O(n) - prints all elements
 * 
 * SPACE COMPLEXITY:
 * - Iterative operations: O(1) - constant extra space
 * - Heapify recursion: O(log n) - recursion stack depth
 */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

void minHeapify(int arr[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest])
        smallest = left;

    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, size, smallest);
    }
}

void buildMaxHeap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, size, i);
    }
}

void buildMinHeap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(arr, size, i);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original: ");
    printArray(data, size);

    buildMaxHeap(data, size);
    printf("Max Heap: ");
    printArray(data, size);

    buildMinHeap(data, size);
    printf("Min Heap: ");
    printArray(data, size);

    return 0;
}