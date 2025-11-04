#include "merge_sort.h"
#include <stdlib.h>

void merge(int *arr, int l, int m, int r) {
  (void)arr;
  (void)l;
  (void)m;
  (void)r;
}

void merge_sort_recursive(int *arr, int l, int r) {
  (void)arr;
  (void)l;
  (void)r;
  // if (l - r <= 1)
  //   return;
  //
  // int m = (l + r) / 2;
  // merge_sort_recursive(arr, l, m);
  // merge_sort_recursive(arr, m + 1, r);
}

void merge_sort(int *arr, size_t size) { merge_sort_recursive(arr, 0, size); }
