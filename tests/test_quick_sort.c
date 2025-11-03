#include "test_framework.h"
#include "quick_sort.h"
#include <string.h>

TEST_SUITE(test_quick_sort_empty_array) {
    printf("\nRunning quick sort tests for empty array...\n");

    int arr[] = {};
    int expected[] = {};

    quick_sort(arr, 0);

    ASSERT_ARRAY_EQUAL(expected, arr, 0, "Empty array should remain empty");
}

TEST_SUITE(test_quick_sort_single_element) {
    printf("\nRunning quick sort tests for single element...\n");

    int arr[] = {42};
    int expected[] = {42};

    quick_sort(arr, 1);

    ASSERT_ARRAY_EQUAL(expected, arr, 1, "Single element array should remain unchanged");
}

TEST_SUITE(test_quick_sort_already_sorted) {
    printf("\nRunning quick sort tests for already sorted array...\n");

    int arr[] = {1, 2, 3, 4, 5};
    int expected[] = {1, 2, 3, 4, 5};

    quick_sort(arr, 5);

    ASSERT_ARRAY_EQUAL(expected, arr, 5, "Already sorted array should remain sorted");
}

TEST_SUITE(test_quick_sort_reverse_sorted) {
    printf("\nRunning quick sort tests for reverse sorted array...\n");

    int arr[] = {5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5};

    quick_sort(arr, 5);

    ASSERT_ARRAY_EQUAL(expected, arr, 5, "Reverse sorted array should be sorted");
}

TEST_SUITE(test_quick_sort_random_order) {
    printf("\nRunning quick sort tests for random order array...\n");

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};

    quick_sort(arr, 7);

    ASSERT_ARRAY_EQUAL(expected, arr, 7, "Random order array should be sorted");
}

TEST_SUITE(test_quick_sort_duplicates) {
    printf("\nRunning quick sort tests for array with duplicates...\n");

    int arr[] = {5, 2, 8, 2, 9, 1, 5};
    int expected[] = {1, 2, 2, 5, 5, 8, 9};

    quick_sort(arr, 7);

    ASSERT_ARRAY_EQUAL(expected, arr, 7, "Array with duplicates should be sorted");
}

TEST_SUITE(test_quick_sort_negative_numbers) {
    printf("\nRunning quick sort tests for negative numbers...\n");

    int arr[] = {-5, 3, -1, 7, -10, 0};
    int expected[] = {-10, -5, -1, 0, 3, 7};

    quick_sort(arr, 6);

    ASSERT_ARRAY_EQUAL(expected, arr, 6, "Array with negative numbers should be sorted");
}

void run_quick_sort_tests(void) {
    printf("\n=== QUICK SORT TESTS ===\n");
    test_quick_sort_empty_array();
    test_quick_sort_single_element();
    test_quick_sort_already_sorted();
    test_quick_sort_reverse_sorted();
    test_quick_sort_random_order();
    test_quick_sort_duplicates();
    test_quick_sort_negative_numbers();
}
