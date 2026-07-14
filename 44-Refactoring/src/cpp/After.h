#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <iomanip>

// AFTER — the same behavior split into focused classes.
namespace after {

// A line item that knows its own subtotal (Tell, Don't Ask).
class LineItem {
    std::string name_;
    double price_;
    int quantity_;
public:
    LineItem(std::string name, double price, int quantity)
        : name_(std::move(name)), price_(price), quantity_(quantity) {}
    const std::string& name() const { return name_; }
    int quantity() const { return quantity_; }
    double subtotal() const { return price_ * quantity_; }
};

// An order that computes its own subtotal (Move Method — no feature envy).
class Order {
    std::vector<LineItem> items_;
public:
    explicit Order(std::vector<LineItem> items) : items_(std::move(items)) {}
    const std::vector<LineItem>& items() const { return items_; }
    double subtotal() const {
        double sum = 0;
        for (const auto& item : items_) sum += item.subtotal();
        return sum;
    }
};

enum class CustomerType { Regular, Premium, Vip };

// Strategy — the discount rule replaces the switch-on-type.
class DiscountStrategy {
public:
    virtual ~DiscountStrategy() = default;
    virtual double discount(double subtotal) const = 0;
};
class RegularDiscount : public DiscountStrategy {
public: double discount(double) const override { return 0; }
};
class PremiumDiscount : public DiscountStrategy {
public: double discount(double s) const override { return s * 0.10; }
};
class VipDiscount : public DiscountStrategy {
public: double discount(double s) const override { return s * 0.20; }
};

// Factory — creation of the strategy in one place.
class DiscountStrategyFactory {
public:
    static std::unique_ptr<DiscountStrategy> for_type(CustomerType type) {
        switch (type) {
            case CustomerType::Regular: return std::make_unique<RegularDiscount>();
            case CustomerType::Premium: return std::make_unique<PremiumDiscount>();
            case CustomerType::Vip:     return std::make_unique<VipDiscount>();
        }
        return std::make_unique<RegularDiscount>();
    }
};

// Single responsibility: tax at a configurable rate.
class TaxCalculator {
    double rate_;
public:
    explicit TaxCalculator(double rate) : rate_(rate) {}
    double tax(double amount) const { return amount * rate_; }
};

// Single responsibility: presentation.
class ReceiptFormatter {
public:
    void print(const Order& order, double subtotal, double discount, double total) const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "  [after]  === RECEIPT ===\n";
        for (const auto& item : order.items())
            std::cout << "  [after]  " << item.name() << " x" << item.quantity()
                      << " = " << item.subtotal() << "\n";
        std::cout << "  [after]  subtotal=" << subtotal << " discount=" << discount
                  << " total=" << total << "\n";
    }
};

// Thin orchestrator — wires the focused collaborators.
class OrderProcessor {
    TaxCalculator tax_;
    ReceiptFormatter formatter_;
public:
    OrderProcessor(TaxCalculator tax, ReceiptFormatter formatter)
        : tax_(tax), formatter_(formatter) {}

    double process(const Order& order, const DiscountStrategy& discountStrategy) const {
        double subtotal = order.subtotal();
        double discount = discountStrategy.discount(subtotal);   // Strategy
        double net = subtotal - discount;
        double total = net + tax_.tax(net);                      // SRP
        formatter_.print(order, subtotal, discount, total);      // SRP
        return total;
    }
};

} // namespace after
