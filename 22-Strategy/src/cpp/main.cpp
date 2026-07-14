#include <iostream>
#include <iomanip>
#include <memory>
#include "ShoppingCart.h"
#include "CreditCardStrategy.h"
#include "PayPalStrategy.h"
#include "CryptoStrategy.h"

int main() {
    std::cout << "=== Strategy Pattern Demo (C++) ===\n";
    std::cout << std::fixed << std::setprecision(2) << "\n";

    ShoppingCart cart;
    cart.add_item("Keyboard", 49.99);
    cart.add_item("Mouse", 25.50);

    // Choose a strategy at runtime
    std::cout << "\nCheckout with credit card:\n";
    cart.set_payment_strategy(std::make_unique<CreditCardStrategy>("1234567812345678"));
    cart.checkout();

    cart.add_item("Monitor", 199.00);
    std::cout << "\nCheckout with PayPal:\n";
    cart.set_payment_strategy(std::make_unique<PayPalStrategy>("shopper@example.com"));
    cart.checkout();

    cart.add_item("Webcam", 60.00);
    std::cout << "\nCheckout with crypto:\n";
    cart.set_payment_strategy(std::make_unique<CryptoStrategy>("0xABCD...1234"));
    cart.checkout();

    return 0;
}
