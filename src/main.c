#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"
#include "quick_sort.h"
#include "bubble_sort.h"

#define ARRAY_SIZE 10

void print_array(int *arr, size_t size) {
    printf("[");
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main(void) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};

    printf("Original array: ");
    print_array(arr, ARRAY_SIZE);

    // TODO: Demonstrate sorting algorithms
    printf("\nSorting algorithms not yet implemented.\n");

    return 0;
}
