#ifndef BAKE_TEST_H
#define BAKE_TEST_H

/* This generated file contains includes for project dependencies */
#include "bake_config.h"
#include "cdiff.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct bake_test_case {
    const char *id;
    void (*function)(void);
} bake_test_case;

typedef struct bake_test_suite {
    const char *id;
    uint32_t testcase_count;
    uint32_t assert_count;
    bake_test_case *testcases;
} bake_test_suite;

int bake_test_run(
    const char *test_id,
    int argc, 
    char *argv[], 
    bake_test_suite *suites,
    uint32_t suite_count);

void _test_assert(
    bool cond,
    const char *cond_str,
    const char *file,
    int line);

void _test_int(
    uint64_t v1,
    uint64_t v2,
    const char *str_v1,
    const char *str_v2,
    const char *file,
    int line);

void _test_flt(
    double v1,
    double v2,
    const char *str_v1,
    const char *str_v2,
    const char *file,
    int line);

void _test_str(
    const char *v1,
    const char *v2,
    const char *str_v1,
    const char *str_v2,
    const char *file,
    int line);

void _test_null(
    void *v,
    const char *str_v,
    const char *file,
    int line);

void _test_not_null(
    void *v,
    const char *str_v,
    const char *file,
    int line);

void _test_ptr(
    void *v1,
    void *v2,
    const char *str_v1,
    const char *str_v2,
    const char *file,
    int line);

#define test_assert(cond) _test_assert(cond, #cond, __FILE__, __LINE__)
#define test_int(v1, v2) _test_int(v1, v2, #v1, #v2, __FILE__, __LINE__)
#define test_flt(v1, v2) _test_flt(v1, v2, #v1, #v2, __FILE__, __LINE__)
#define test_str(v1, v2) _test_str(v1, v2, #v1, #v2, __FILE__, __LINE__)
#define test_null(v) _test_null(v, #v, __FILE__, __LINE__)
#define test_not_null(v) _test_not_null(v, #v, __FILE__, __LINE__)
#define test_ptr(v1, v2) _test_ptr(v1, v2, #v1, #v2, __FILE__, __LINE__)

#ifdef __cplusplus
}
#endif

#endif
