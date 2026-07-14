#pragma once
#include <iostream>
#include <string>
#include <cmath>

// A tiny hand-rolled assert harness — stands in for GoogleTest/Catch2 so the
// examples run anywhere. Tracks pass/fail counts and prints a result per check.
class TestSupport {
    int passed_ = 0;
    int failed_ = 0;

    void pass(const std::string& name) { passed_++; std::cout << "  PASS  " << name << "\n"; }
    void fail(const std::string& name) { failed_++; std::cout << "  FAIL  " << name << "\n"; }

public:
    template <class T>
    void assert_equals(const T& expected, const T& actual, const std::string& name) {
        if (expected == actual) pass(name);
        else { std::cout << "  FAIL  " << name << " (expected " << expected
                         << ", got " << actual << ")\n"; failed_++; }
    }

    void assert_equals_double(double expected, double actual, const std::string& name) {
        if (std::abs(expected - actual) < 1e-9) pass(name);
        else { std::cout << "  FAIL  " << name << " (expected " << expected
                         << ", got " << actual << ")\n"; failed_++; }
    }

    void assert_true(bool condition, const std::string& name) {
        if (condition) pass(name); else fail(name);
    }

    void summary() const {
        std::cout << "\n  " << passed_ << " passed, " << failed_ << " failed\n";
    }
};
