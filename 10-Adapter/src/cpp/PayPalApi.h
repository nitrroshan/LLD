#pragma once
#include <string>
#include <iostream>
#include <chrono>

// Third-party PayPal API — different interface, amounts as float
class PayPalApi {
public:
    struct PayPalResponse {
        int status_code;  // 0 = success
        std::string payment_id;
    };

    PayPalResponse send_payment(float amount, const std::string& currency_code) {
        std::cout << "  [PayPal] Sending " << amount << " " << currency_code << "\n";
        auto now = std::chrono::steady_clock::now().time_since_epoch().count();
        return {0, "PAY-" + std::to_string(now)};
    }

    PayPalResponse reverse_payment(const std::string& payment_id) {
        std::cout << "  [PayPal] Reversing payment " << payment_id << "\n";
        auto now = std::chrono::steady_clock::now().time_since_epoch().count();
        return {0, "REV-" + std::to_string(now)};
    }
};
