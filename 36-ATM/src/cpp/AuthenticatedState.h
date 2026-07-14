#pragma once
#include <iostream>
#include "ATMState.h"
#include "ATM.h"
#include "Transaction.h"
#include "Card.h"

// Authenticated — PIN verified. Runs transactions and ejects the card.
class AuthenticatedState : public ATMState {
    ATM& atm_;

public:
    explicit AuthenticatedState(ATM& atm) : atm_(atm) {}

    void insert_card(Card&) override { std::cout << "  Finish the current session first\n"; }
    void enter_pin(const std::string&) override { std::cout << "  Already authenticated\n"; }

    void perform_transaction(Transaction& transaction) override {
        std::cout << "  > " << transaction.description() << "\n";
        transaction.execute();
    }

    void eject_card() override {
        std::cout << "  Session ended. Card ejected.\n";
        atm_.reset_session();
        atm_.set_state(atm_.idle_state());
    }

    const char* name() const override { return "AUTHENTICATED"; }
};
