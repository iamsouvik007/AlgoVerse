#include <stdio.h>

// Function declarations
void mergeSort(int arr[], int start, int end);
void merge(int arr[], int start, int mid, int end);

int main() {
    int arr[100];
    int i, size;

    // Get the number of elements with basic input validation
    printf("Enter number of elements (max 100): ");
    scanf("%d", &size);
    if (size <= 0 || size > 100) {
        printf("Invalid size! Please enter a number between 1 and 100.\n");
        return 1;
    }

    // Input array elements
    for (i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Sort the array
    mergeSort(arr, 0, size - 1);

    // Print sorted array
    printf("\nNumbers after sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d   ", arr[i]);
    }
    printf("\n");

    return 0;
}


 
void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2; // Avoid potential overflow
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}


void merge(int arr[], int start, int mid, int end) {
    int temp[100]; // Temporary array (still limited to 100 elements)
    int left = start;    // Index for left subarray
    int right = mid + 1; // Index for right subarray
    int tempIndex = start; // Index for temp array

    // Merge the two subarrays into temp
    while (left <= mid && right <= end) {
        if (arr[left] < arr[right]) {
            temp[tempIndex++] = arr[left++];
        } else if (arr[right] < arr[left]) {
            temp[tempIndex++] = arr[right++];
        } else {
            // Handle equal elements for stability
            temp[tempIndex++] = arr[left++];
            temp[tempIndex++] = arr[right++];
        }
    }

    // Copy remaining elements from left subarray, if any
    while (left <= mid) {
        temp[tempIndex++] = arr[left++];
    }

    // Copy remaining elements from right subarray, if any
    while (right <= end) {
        temp[tempIndex++] = arr[right++];
    }

    // Copy merged elements back to original array
    for (int i = start; i <= end; i++) {
        arr[i] = temp[i];
    }
}