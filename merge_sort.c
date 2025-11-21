#include <stdio.h>

// Function to merge two sorted halves
//int left is start index of any subarray,right is end index of any subarray
void merge(int arr[], int left, int mid, int right) {
    int i = left;      // starting index of left subarray
    int j = mid + 1;   // starting index of right subarray
    int k = 0;         // index for temp array

    int temp[100];     // temporary array

    // Merge the two subarrays in sorted order
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left subarray
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements of right subarray
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy back the merged elements into original array
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

// Function to divide array and call merge
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[50], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

