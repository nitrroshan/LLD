#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <stdexcept>
#include "SplitStrategy.h"

// Concrete Strategy — each participant pays a pre-specified exact amount.
class ExactSplitStrategy : public SplitStrategy {
    std::unordered_map<std::string, double> exact_by_id_;

public:
    explicit ExactSplitStrategy(std::unordered_map<std::string, double> exact_by_id)
        : exact_by_id_(std::move(exact_by_id)) {}

    std::vector<Split> calculate_splits(double total,
                                        const std::vector<User*>& participants) const override {
        std::vector<Split> splits;
        double sum = 0;
        for (User* user : participants) {
            auto it = exact_by_id_.find(user->id());
            double amount = it != exact_by_id_.end() ? it->second : 0.0;
            splits.push_back(Split{user, amount});
            sum += amount;
        }
        if (std::abs(sum - total) > 0.01) {
            throw std::invalid_argument("Exact splits must sum to the total");
        }
        return splits;
    }
};
