#include <stdio.h>

// linear search function
void linearSearch(int arr[], int n, int key) {
    int i;

    for (i = 0; i < n; i++) {            // check each element
        if (arr[i] == key) {             // if element matches key
            printf("Element %d found at index %d\n", key, i);
            return;                      // exit function after finding
        }
    }

    printf("Element %d not found in array\n", key);
}

int main() {
    int arr[100], n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    linearSearch(arr, n, key);

    return 0;
}



