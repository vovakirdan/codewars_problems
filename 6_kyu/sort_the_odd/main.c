#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Main function to sort odd numbers
void sort_array(size_t n, int arr[n]) {
    // First, collect all the odd numbers
    int temp[n];  // Temporary array to store odd numbers
    size_t j = 0;
    
    // Collect the odd numbers in a temporary array
    for (size_t i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            temp[j++] = arr[i];
        }
    }
    
    // Sort the temporary array of odd numbers using quicksort
    if (j > 0) {
        quickSort(temp, 0, j - 1);
    }
    
    // Reinsert the sorted odd numbers back into the original array
    j = 0;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            arr[i] = temp[j++];
        }
    }
}
