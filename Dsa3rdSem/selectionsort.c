#include <stdio.h>


void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selection_sort(int arr[], int n) {
    int i, j, min;

    for (i = 0; i < n - 1; i++) {
    
        min= i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min= j;
            }
        }

        // Swap the found minimum element with the first element
        swap(&arr[min], &arr[i]);
    }
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    print_array(arr, n);

    selection_sort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}
