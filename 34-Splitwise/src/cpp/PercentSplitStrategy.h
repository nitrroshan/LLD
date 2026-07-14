#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <stdexcept>
#include "SplitStrategy.h"

// Concrete Strategy — split by percentage; percentages must sum to 100.
class PercentSplitStrategy : public SplitStrategy {
    std::unordered_map<std::string, double> percent_by_id_;

    static double round2(double v) { return std::round(v * 100.0) / 100.0; }

public:
    explicit PercentSplitStrategy(std::unordered_map<std::string, double> percent_by_id)
        : percent_by_id_(std::move(percent_by_id)) {}

    std::vector<Split> calculate_splits(double total,
                                        const std::vector<User*>& participants) const override {
        double percent_sum = 0;
        for (User* user : participants) {
            auto it = percent_by_id_.find(user->id());
            percent_sum += it != percent_by_id_.end() ? it->second : 0.0;
        }
        if (std::abs(percent_sum - 100.0) > 0.01) {
            throw std::invalid_argument("Percentages must sum to 100");
        }
        std::vector<Split> splits;
        for (User* user : participants) {
            auto it = percent_by_id_.find(user->id());
            double percent = it != percent_by_id_.end() ? it->second : 0.0;
            splits.push_back(Split{user, round2(total * percent / 100.0)});
        }
        return splits;
    }
};
