#include <stdio.h>

void linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at index %d (Linear Search)\n", key, i);
            return;
        }
    }
    printf("Element %d not found (Linear Search)\n", key);
}

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, key, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements (sorted for binary search):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nSearch Operations:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search (Linear Search): ");
                scanf("%d", &key);
                linearSearch(arr, n, key);
                break;
            case 2:
                printf("Enter element to search (Binary Search): ");
                scanf("%d", &key);
                int result = binarySearch(arr, 0, n - 1, key);
                if (result != -1) {
                    printf("Element %d found at index %d (Binary Search)\n", key, result);
                } else {
                    printf("Element %d not found (Binary Search)\n", key);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}