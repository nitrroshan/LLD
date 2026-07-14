#pragma once
#include <vector>
#include "Split.h"
#include "User.h"

// Strategy — turns a total into per-participant splits.
class SplitStrategy {
public:
    virtual ~SplitStrategy() = default;
    virtual std::vector<Split> calculate_splits(double total,
                                                const std::vector<User*>& participants) const = 0;
};
