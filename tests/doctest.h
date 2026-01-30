// Simplified Doctest-compatible test framework
// This is a minimal implementation for testing purposes
// For production, download the full doctest.h from: https://github.com/doctest/doctest

#pragma once
#include <iostream>
#include <string>
#include <vector>

struct TestResult {
    std::string name;
    bool passed;
    std::string message;
};

std::vector<TestResult> g_tests;
int g_failed = 0;

#define CHECK(condition) \
    if (!(condition)) { \
        std::cerr << "CHECK failed at " << __FILE__ << ":" << __LINE__ << std::endl; \
        g_failed++; \
    }

#define TEST_CASE(name) \
    void test_##__LINE__(); \
    struct TestRegistrar_##__LINE__ { \
        TestRegistrar_##__LINE__() { \
            test_##__LINE__(); \
        } \
    } registrar_##__LINE__; \
    void test_##__LINE__()

#ifdef DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
int main() {
    std::cout << "Running tests...\n";
    if (g_failed == 0) {
        std::cout << "All tests passed!\n";
        return 0;
    } else {
        std::cout << g_failed << " test(s) failed.\n";
        return 1;
    }
}
#endif
