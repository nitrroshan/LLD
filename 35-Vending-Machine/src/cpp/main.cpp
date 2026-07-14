#include <iostream>
#include <memory>
#include "VendingMachine.h"
#include "IdleState.h"
#include "AwaitingPaymentState.h"
#include "DispensingState.h"
#include "Inventory.h"
#include "CoinHandlers.h"
#include "CardPaymentStrategy.h"

// Defined here, where the concrete state classes are complete, which breaks the
// VendingMachine <-> concrete-state definition cycle.
VendingMachine::VendingMachine(Inventory& inventory, std::unique_ptr<CoinHandler> coin_chain)
    : inventory_(inventory), coin_chain_(std::move(coin_chain)) {
    idle_ = std::make_unique<IdleState>(*this);
    awaiting_ = std::make_unique<AwaitingPaymentState>(*this);
    dispensing_ = std::make_unique<DispensingState>(*this);
    current_ = idle_.get();
}

int main() {
    std::cout << "=== Vending Machine Demo (C++) ===\n\n";

    Inventory inventory;
    inventory.add_product(Product("A1", "Coke", 125), 2);
    inventory.add_product(Product("A2", "Water", 100), 1);
    inventory.add_product(Product("A3", "Chips", 75), 0);   // out of stock

    // Coin acceptor chain (Chain of Responsibility).
    auto coin_chain = std::make_unique<NickelHandler>();
    coin_chain->set_next(std::make_unique<DimeHandler>())
              ->set_next(std::make_unique<QuarterHandler>())
              ->set_next(std::make_unique<DollarHandler>());

    VendingMachine machine(inventory, std::move(coin_chain));

    // 1) Cash purchase (State + Chain of Responsibility).
    std::cout << "Cash purchase of Water ($1.00):\n";
    machine.select_product("A2");
    machine.insert_coin(Coin::Quarter);
    machine.insert_coin(Coin::Penny);    // rejected by the chain
    machine.insert_coin(Coin::Dollar);   // $1.25 >= $1.00 -> dispense + change

    // 2) Card purchase (State + Strategy).
    std::cout << "\nCard purchase of Coke ($1.25):\n";
    machine.select_product("A1");
    CardPaymentStrategy card("1234567812349999");
    machine.pay_with(card);

    // 3) Out of stock.
    std::cout << "\nTry to buy Chips (out of stock):\n";
    machine.select_product("A3");

    // 4) Cancel / refund.
    std::cout << "\nSelect Coke, insert a quarter, then cancel:\n";
    machine.select_product("A1");
    machine.insert_coin(Coin::Quarter);
    machine.cancel();

    std::cout << "\nState machine + coin chain + payment strategy,\n";
    std::cout << "each pattern owning one concern.\n";

    return 0;
}
