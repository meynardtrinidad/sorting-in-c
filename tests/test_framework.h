#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>
#include <string.h>

/* Test statistics */
extern int tests_run;
extern int tests_passed;
extern int tests_failed;

/* Test macros */
#define ASSERT_TRUE(condition, message) \
    do { \
        tests_run++; \
        if (condition) { \
            tests_passed++; \
            printf("  [PASS] %s\n", message); \
        } else { \
            tests_failed++; \
            printf("  [FAIL] %s\n", message); \
        } \
    } while (0)

#define ASSERT_EQUAL(expected, actual, message) \
    do { \
        tests_run++; \
        if ((expected) == (actual)) { \
            tests_passed++; \
            printf("  [PASS] %s\n", message); \
        } else { \
            tests_failed++; \
            printf("  [FAIL] %s (expected: %d, got: %d)\n", message, expected, actual); \
        } \
    } while (0)

#define ASSERT_ARRAY_EQUAL(expected, actual, size, message) \
    do { \
        tests_run++; \
        int arrays_equal = 1; \
        for (size_t i = 0; i < (size); i++) { \
            if ((expected)[i] != (actual)[i]) { \
                arrays_equal = 0; \
                break; \
            } \
        } \
        if (arrays_equal) { \
            tests_passed++; \
            printf("  [PASS] %s\n", message); \
        } else { \
            tests_failed++; \
            printf("  [FAIL] %s\n", message); \
        } \
    } while (0)

/* Test suite declaration */
#define TEST_SUITE(name) \
    void name(void); \
    void name(void)

/* Print test summary */
void print_test_summary(void);

#endif /* TEST_FRAMEWORK_H */
