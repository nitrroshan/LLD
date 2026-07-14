#pragma once
#include <memory>
#include <string>
#include "ATMState.h"
#include "BankService.h"
#include "CashDispenser.h"

class Card;
class Account;
class Transaction;

// Context — the ATM terminal. Holds the current state, the inserted card and
// authenticated account, the cash dispenser, and the bank. All user actions
// delegate to the current state. The constructor (which creates the concrete
// states) is defined in main.cpp, breaking the ATM <-> state definition cycle.
class ATM {
    BankService& bank_;
    CashDispenser& dispenser_;
    std::unique_ptr<ATMState> idle_;
    std::unique_ptr<ATMState> has_card_;
    std::unique_ptr<ATMState> authenticated_;
    ATMState* current_ = nullptr;
    Card* current_card_ = nullptr;
    Account* current_account_ = nullptr;
    int pin_attempts_ = 0;

public:
    ATM(BankService& bank, CashDispenser& dispenser);

    // User actions — delegate to the current state.
    void insert_card(Card& card) { current_->insert_card(card); }
    void enter_pin(const std::string& pin) { current_->enter_pin(pin); }
    void perform_transaction(Transaction& transaction) { current_->perform_transaction(transaction); }
    void eject_card() { current_->eject_card(); }

    // Context helpers used by the states.
    void set_state(ATMState* state) { current_ = state; }
    BankService& bank() { return bank_; }
    CashDispenser& dispenser() { return dispenser_; }
    void set_current_card(Card* card) { current_card_ = card; }
    Card* current_card() { return current_card_; }
    void set_current_account(Account* account) { current_account_ = account; }
    Account* current_account() { return current_account_; }
    int pin_attempts() const { return pin_attempts_; }
    void increment_pin_attempts() { ++pin_attempts_; }
    void reset_session() {
        current_card_ = nullptr;
        current_account_ = nullptr;
        pin_attempts_ = 0;
    }

    ATMState* idle_state() { return idle_.get(); }
    ATMState* has_card_state() { return has_card_.get(); }
    ATMState* authenticated_state() { return authenticated_.get(); }
};
