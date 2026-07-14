#pragma once
#include <iostream>
#include "ATMState.h"
#include "ATM.h"
#include "Card.h"
#include "Account.h"

// HasCard — a card is inserted, awaiting PIN. Limited attempts, then the card
// is retained and the ATM returns to Idle.
class HasCardState : public ATMState {
    static constexpr int kMaxAttempts = 3;
    ATM& atm_;

public:
    explicit HasCardState(ATM& atm) : atm_(atm) {}

    void insert_card(Card&) override { std::cout << "  A card is already inserted\n"; }

    void enter_pin(const std::string& pin) override {
        Account* account = atm_.bank().authenticate(*atm_.current_card(), pin);
        if (account) {
            atm_.set_current_account(account);
            std::cout << "  PIN accepted. Choose a transaction.\n";
            atm_.set_state(atm_.authenticated_state());
            return;
        }
        atm_.increment_pin_attempts();
        if (atm_.pin_attempts() >= kMaxAttempts) {
            std::cout << "  Too many wrong PIN attempts. Card retained.\n";
            atm_.reset_session();
            atm_.set_state(atm_.idle_state());
        } else {
            std::cout << "  Wrong PIN. Attempts left: " << (kMaxAttempts - atm_.pin_attempts()) << "\n";
        }
    }

    void perform_transaction(Transaction&) override { std::cout << "  Authenticate with your PIN first\n"; }

    void eject_card() override {
        std::cout << "  Card ejected\n";
        atm_.reset_session();
        atm_.set_state(atm_.idle_state());
    }

    const char* name() const override { return "HAS_CARD"; }
};
