#pragma once
#include <string>
#include <iostream>
#include <chrono>

// Third-party Stripe API — different interface, amounts in cents
class StripeApi {
public:
    struct StripeResult {
        bool success;
        std::string id;
    };

    StripeResult create_charge(int cents, const std::string& currency, const std::string& token) {
        std::cout << "  [Stripe] Charging " << cents << " cents (" << currency << ") token=" << token << "\n";
        auto now = std::chrono::steady_clock::now().time_since_epoch().count();
        return {true, "ch_" + std::to_string(now)};
    }

    StripeResult create_refund(const std::string& charge_id) {
        std::cout << "  [Stripe] Refunding charge " << charge_id << "\n";
        auto now = std::chrono::steady_clock::now().time_since_epoch().count();
        return {true, "re_" + std::to_string(now)};
    }
};
