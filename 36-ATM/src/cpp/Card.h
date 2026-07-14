#pragma once
#include <string>
#include <utility>

// A physical card. Carries the card number and the account it maps to.
class Card {
    std::string card_number_;
    std::string account_number_;

public:
    Card(std::string card_number, std::string account_number)
        : card_number_(std::move(card_number)), account_number_(std::move(account_number)) {}

    const std::string& card_number() const { return card_number_; }
    const std::string& account_number() const { return account_number_; }
};
