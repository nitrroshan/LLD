#pragma once
#include <memory>
#include <string>
#include "Inventory.h"
#include "CoinHandler.h"
#include "VendingMachineState.h"

class PaymentStrategy;

// Context — holds inventory, the coin chain, the current state, and the
// transaction data. All user actions delegate to the current state. The
// constructor (which creates the concrete states) is defined in main.cpp.
class VendingMachine {
    Inventory& inventory_;
    std::unique_ptr<CoinHandler> coin_chain_;
    std::unique_ptr<VendingMachineState> idle_;
    std::unique_ptr<VendingMachineState> awaiting_;
    std::unique_ptr<VendingMachineState> dispensing_;
    VendingMachineState* current_ = nullptr;
    int balance_ = 0;
    std::string selected_code_;

public:
    VendingMachine(Inventory& inventory, std::unique_ptr<CoinHandler> coin_chain);

    // User actions — delegate to the current state.
    void select_product(const std::string& code) { current_->select_product(code); }
    void insert_coin(Coin coin) { current_->insert_coin(coin); }
    void pay_with(PaymentStrategy& strategy) { current_->pay_with(strategy); }
    void cancel() { current_->cancel(); }

    // Context helpers used by the states.
    void set_state(VendingMachineState* state) { current_ = state; }
    Inventory& inventory() { return inventory_; }
    CoinHandler* coin_chain() { return coin_chain_.get(); }
    int balance() const { return balance_; }
    void add_balance(int cents) { balance_ += cents; }
    void reset() { balance_ = 0; selected_code_.clear(); }
    void set_selected_code(const std::string& code) { selected_code_ = code; }
    Product* selected_product() { return inventory_.get_product(selected_code_); }

    VendingMachineState* idle_state() { return idle_.get(); }
    VendingMachineState* awaiting_payment_state() { return awaiting_.get(); }
    VendingMachineState* dispensing_state() { return dispensing_.get(); }
};
