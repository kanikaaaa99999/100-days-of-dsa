#include <stdio.h>

// Max heapify: maintain heap property at index i
void maxHeapify(int arr[], int n, int i) {
    int largest = i;      // Assume root is largest
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2;// Right child
    
    // Check if left child exists and is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    // Check if right child exists and is larger  
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    // If largest != root, swap and heapify affected subtree
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

// Build max heap from array (O(n))
void buildMaxHeap(int arr[], int n) {
    // Start from last non-leaf node, heapify bottom-up
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Heap Sort: O(n log n)
void heapSort(int arr[], int n) {
    // Step 1: Build max heap
    buildMaxHeap(arr, n);
    
    // Step 2: Extract max elements one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (max) to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        // Heapify reduced heap
        maxHeapify(arr, i, 0);
    }
}

// Test driver
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    
    heapSort(arr, n);
    
    printf("\nSorted:   ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
