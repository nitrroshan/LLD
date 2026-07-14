#pragma once
#include <iostream>
#include <iomanip>
#include "VendingMachineState.h"
#include "VendingMachine.h"

// Dispensing — releases the item, returns change, and resets to Idle.
class DispensingState : public VendingMachineState {
    VendingMachine& machine_;

public:
    explicit DispensingState(VendingMachine& machine) : machine_(machine) {}

    void dispense() override {
        Product* product = machine_.selected_product();
        machine_.inventory().reduce_stock(product->code());
        int change = machine_.balance() - product->price_cents();
        std::cout << "  Dispensing " << product->name() << "\n";
        if (change > 0) {
            std::cout << "  Returning change $"
                      << std::fixed << std::setprecision(2) << change / 100.0 << "\n";
        }
        machine_.reset();
        machine_.set_state(machine_.idle_state());
    }

    void select_product(const std::string&) override { std::cout << "  Please wait, dispensing\n"; }
    void insert_coin(Coin) override { std::cout << "  Please wait, dispensing\n"; }
    void pay_with(PaymentStrategy&) override { std::cout << "  Please wait, dispensing\n"; }
    void cancel() override { std::cout << "  Too late to cancel, dispensing\n"; }
    const char* name() const override { return "DISPENSING"; }
};
