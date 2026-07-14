#pragma once
#include <iostream>
#include <iomanip>
#include "VendingMachineState.h"
#include "VendingMachine.h"
#include "PaymentStrategy.h"

// AwaitingPayment — accepting money (coins via the chain, or an instant payment
// strategy) until the price is met, then transitioning to dispensing.
class AwaitingPaymentState : public VendingMachineState {
    VendingMachine& machine_;

    void dispense_if_funded() {
        Product* product = machine_.selected_product();
        if (machine_.balance() >= product->price_cents()) {
            machine_.set_state(machine_.dispensing_state());
            machine_.dispensing_state()->dispense();
        }
    }

public:
    explicit AwaitingPaymentState(VendingMachine& machine) : machine_(machine) {}

    void select_product(const std::string&) override {
        std::cout << "  Finish paying or cancel the current selection first\n";
    }

    void insert_coin(Coin coin) override {
        int accepted = machine_.coin_chain()->handle(coin);   // Chain of Responsibility
        if (accepted == 0) {
            std::cout << "  Rejected coin: " << to_string(coin) << " (returned)\n";
            return;
        }
        machine_.add_balance(accepted);
        Product* product = machine_.selected_product();
        std::cout << "  Inserted " << to_string(coin) << ". Balance $"
                  << std::fixed << std::setprecision(2) << machine_.balance() / 100.0
                  << " / $" << product->price_cents() / 100.0 << "\n";
        dispense_if_funded();
    }

    void pay_with(PaymentStrategy& strategy) override {
        Product* product = machine_.selected_product();
        int due = product->price_cents() - machine_.balance();
        if (strategy.pay(due)) {
            machine_.add_balance(due);
            dispense_if_funded();
        } else {
            std::cout << "  Payment failed\n";
        }
    }

    void cancel() override {
        int refund = machine_.balance();
        if (refund > 0) {
            std::cout << "  Refunding $" << std::fixed << std::setprecision(2) << refund / 100.0 << "\n";
        }
        machine_.reset();
        machine_.set_state(machine_.idle_state());
        std::cout << "  Cancelled\n";
    }

    const char* name() const override { return "AWAITING_PAYMENT"; }
};
