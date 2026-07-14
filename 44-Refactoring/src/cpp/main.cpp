#include <iostream>
#include <cmath>
#include <vector>
#include "Before.h"
#include "After.h"

int main() {
    std::cout << "=== Refactoring Demo (C++) ===\n\n";

    // BEFORE — the God class with a long method + switch-on-type.
    std::cout << "Before (smelly):\n";
    before::OrderProcessorBefore before_proc;
    double before_total = before_proc.process(2, {   // 2 = VIP (magic int)
        {"Widget", 100, 2},
        {"Gadget", 50, 1}});

    // AFTER — focused classes wired by a thin orchestrator.
    std::cout << "\nAfter (refactored):\n";
    after::Order order({
        after::LineItem("Widget", 100, 2),
        after::LineItem("Gadget", 50, 1)});
    after::OrderProcessor processor(after::TaxCalculator(0.08), after::ReceiptFormatter());
    auto strategy = after::DiscountStrategyFactory::for_type(after::CustomerType::Vip);
    double after_total = processor.process(order, *strategy);

    std::cout << "\nSame behavior? " << (std::abs(before_total - after_total) < 1e-9 ? "true" : "false")
              << "  (before=" << before_total << ", after=" << after_total << ")\n";

    return 0;
}
