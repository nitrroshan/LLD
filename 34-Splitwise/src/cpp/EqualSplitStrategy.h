#pragma once
#include <vector>
#include <cmath>
#include "SplitStrategy.h"

// Concrete Strategy — divide equally; the first participant absorbs any
// rounding remainder so shares sum exactly to the total.
class EqualSplitStrategy : public SplitStrategy {
    static double round2(double v) { return std::round(v * 100.0) / 100.0; }

public:
    std::vector<Split> calculate_splits(double total,
                                        const std::vector<User*>& participants) const override {
        int n = static_cast<int>(participants.size());
        double each = round2(total / n);
        std::vector<Split> splits;
        for (int i = 0; i < n; i++) {
            double share = (i == 0) ? total - each * (n - 1) : each;
            splits.push_back(Split{participants[i], round2(share)});
        }
        return splits;
    }
};
