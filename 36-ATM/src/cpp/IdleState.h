#pragma once
#include <iostream>
#include "ATMState.h"
#include "ATM.h"
#include "Card.h"

// Idle — no card inserted. Only inserting a card does anything.
class IdleState : public ATMState {
    ATM& atm_;

public:
    explicit IdleState(ATM& atm) : atm_(atm) {}

    void insert_card(Card& card) override {
        atm_.set_current_card(&card);
        std::cout << "  Card inserted (" << card.card_number() << "). Enter PIN.\n";
        atm_.set_state(atm_.has_card_state());
    }

    void enter_pin(const std::string&) override { std::cout << "  Insert a card first\n"; }
    void perform_transaction(Transaction&) override { std::cout << "  Insert a card first\n"; }
    void eject_card() override { std::cout << "  No card to eject\n"; }
    const char* name() const override { return "IDLE"; }
};
