#include "test_framework.h"

/* Test suite declarations */
void run_merge_sort_tests(void);
void run_quick_sort_tests(void);
void run_bubble_sort_tests(void);

int main(void) {
    printf("Starting test suite...\n");
    printf("=================================\n");

    /* Run all test suites */
    run_merge_sort_tests();
    run_quick_sort_tests();
    run_bubble_sort_tests();

    /* Print summary */
    print_test_summary();

    /* Return 0 if all tests passed, 1 otherwise */
    return (tests_failed == 0) ? 0 : 1;
}
