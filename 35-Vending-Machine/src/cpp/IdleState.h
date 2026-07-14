#pragma once
#include <iostream>
#include <iomanip>
#include "VendingMachineState.h"
#include "VendingMachine.h"

// Idle — waiting for a product selection.
class IdleState : public VendingMachineState {
    VendingMachine& machine_;

public:
    explicit IdleState(VendingMachine& machine) : machine_(machine) {}

    void select_product(const std::string& code) override {
        Product* product = machine_.inventory().get_product(code);
        if (!product) {
            std::cout << "  No product at slot " << code << "\n";
            return;
        }
        if (!machine_.inventory().is_in_stock(code)) {
            std::cout << "  " << product->name() << " is out of stock\n";
            return;
        }
        machine_.set_selected_code(code);
        std::cout << "  Selected " << product->name() << " ($"
                  << std::fixed << std::setprecision(2) << product->price_cents() / 100.0
                  << "). Insert coins or pay by card.\n";
        machine_.set_state(machine_.awaiting_payment_state());
    }

    void insert_coin(Coin) override { std::cout << "  Select a product first\n"; }
    void pay_with(PaymentStrategy&) override { std::cout << "  Select a product first\n"; }
    void cancel() override { std::cout << "  Nothing to cancel\n"; }
    const char* name() const override { return "IDLE"; }
};
