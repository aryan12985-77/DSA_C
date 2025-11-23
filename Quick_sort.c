#include <stdio.h>

// Function to print array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Partition function (pivot = first element)
int partition(int arr[], int low, int high) {
    int pivot = arr[low];     // pivot = first element
    int p = low + 1;          // pointer just after pivot
    int q = high;             // pointer at last element
    int temp;

    while (p <= q) {

        // Move p forward until arr[p] > pivot
        while (p <= high && arr[p] <= pivot)
            p++;

        // Move q backward until arr[q] < pivot
        while (q >= low && arr[q] > pivot)
            q--;

        // If p < q, swap
        if (p < q) {
            temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
        }
    }

    // Now p > q, swap pivot with arr[q]
    temp = arr[low];
    arr[low] = arr[q];
    arr[q] = temp;

    return q;    // pivot index
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {

        int pivotIndex = partition(arr, low, high);

        // Sort left part
        quickSort(arr, low, pivotIndex - 1);

        // Sort right part
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    //readArray
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

