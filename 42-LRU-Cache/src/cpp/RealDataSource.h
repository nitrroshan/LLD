#pragma once
#include <string>
#include <iostream>
#include "DataSource.h"

// The slow backing store (a simulated database). Prints when it's hit so the
// proxy's caching is visible.
class RealDataSource : public DataSource<int, std::string> {
public:
    std::string get(const int& key) override {
        std::cout << "    [DB] fetching " << key << "\n";   // slow
        return "User#" + std::to_string(key);
    }
};
