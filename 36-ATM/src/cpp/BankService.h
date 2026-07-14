#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include "Account.h"
#include "Card.h"

// The bank behind the ATM. Owns accounts and authenticates a card + PIN.
// Keeping balances here (not in the ATM) makes the ATM a thin terminal.
class BankService {
    std::unordered_map<std::string, std::unique_ptr<Account>> accounts_;

public:
    void add_account(std::unique_ptr<Account> account) {
        accounts_[account->account_number()] = std::move(account);
    }

    // Returns the account if the card maps to it and the PIN matches, else nullptr.
    Account* authenticate(const Card& card, const std::string& pin) {
        auto it = accounts_.find(card.account_number());
        if (it != accounts_.end() && it->second->verify_pin(pin)) {
            return it->second.get();
        }
        return nullptr;
    }

    Account* get_account(const std::string& account_number) {
        auto it = accounts_.find(account_number);
        return it == accounts_.end() ? nullptr : it->second.get();
    }
};
