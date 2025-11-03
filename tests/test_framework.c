#include "test_framework.h"

int tests_run = 0;
int tests_passed = 0;
int tests_failed = 0;

void print_test_summary(void) {
    printf("\n");
    printf("=================================\n");
    printf("Test Summary:\n");
    printf("  Total:  %d\n", tests_run);
    printf("  Passed: %d\n", tests_passed);
    printf("  Failed: %d\n", tests_failed);
    printf("=================================\n");

    if (tests_failed == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Some tests failed.\n");
    }
}
