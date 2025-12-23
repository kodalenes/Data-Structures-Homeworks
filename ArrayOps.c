#include <stdio.h>

/*
 * TIME COMPLEXITY ANALYSIS:
 * - printArray(): O(n) - iterates through all elements
 * - insertElement(): O(n) - worst case shifts all elements
 * - deleteElement(): O(n) - worst case shifts all elements
 * 
 * SPACE COMPLEXITY: O(1) - uses constant extra space
 */

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *size, int element, int pos) {
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    (*size)++;
}

void deleteElement(int arr[], int *size, int pos) {
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;

    printf("Current Array: ");
    printArray(arr, size);

    insertElement(arr, &size, 25, 2);
    printf("After Insertion: ");
    printArray(arr, size);

    deleteElement(arr, &size, 3);
    printf("After Deletion:  ");
    printArray(arr, size);

    return 0;
}