#pragma once
#include <vector>
#include <string>
#include <functional>

// Strategy under test — pure and trivially testable.
class DiscountStrategy {
public:
    virtual ~DiscountStrategy() = default;
    virtual double discount(double subtotal) const = 0;
};

class VipDiscount : public DiscountStrategy {
public:
    double discount(double subtotal) const override { return subtotal * 0.20; }
};

// A minimal subject that notifies observers — the target of an interaction test.
class EventSource {
    std::vector<std::function<void(const std::string&)>> observers_;
public:
    void add_observer(std::function<void(const std::string&)> obs) {
        observers_.push_back(std::move(obs));
    }
    void fire(const std::string& event) {
        for (auto& o : observers_) o(event);
    }
};
