#pragma once
#include <string>

class Card;
class Transaction;

// State — each concrete state defines how the four ATM actions behave and what
// transition follows. Acting out of order is refused by the current state.
class ATMState {
public:
    virtual ~ATMState() = default;
    virtual void insert_card(Card& card) = 0;
    virtual void enter_pin(const std::string& pin) = 0;
    virtual void perform_transaction(Transaction& transaction) = 0;
    virtual void eject_card() = 0;
    virtual const char* name() const = 0;
};
