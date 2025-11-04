#include "bubble_sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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
  int size = sizeof(arr) / sizeof(int);

  printf("Original array: ");
  print_array(arr, ARRAY_SIZE);

  // printf("Merge sort: ");
  // merge_sort(arr, size);
  // print_array(arr, ARRAY_SIZE);

  printf("Bubble sort: ");
  bubble_sort(arr, size);
  print_array(arr, ARRAY_SIZE);

  return 0;
}
