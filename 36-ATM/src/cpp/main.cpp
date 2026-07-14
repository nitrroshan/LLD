#include <iostream>
#include <memory>
#include "ATM.h"
#include "IdleState.h"
#include "HasCardState.h"
#include "AuthenticatedState.h"
#include "BankService.h"
#include "CashDispenser.h"
#include "DenominationHandlers.h"
#include "WithdrawTransaction.h"
#include "DepositTransaction.h"
#include "BalanceInquiryTransaction.h"
#include "Card.h"

// Defined here, where the concrete state classes are complete, which breaks the
// ATM <-> concrete-state definition cycle.
ATM::ATM(BankService& bank, CashDispenser& dispenser)
    : bank_(bank), dispenser_(dispenser) {
    idle_ = std::make_unique<IdleState>(*this);
    has_card_ = std::make_unique<HasCardState>(*this);
    authenticated_ = std::make_unique<AuthenticatedState>(*this);
    current_ = idle_.get();
}

int main() {
    std::cout << "=== ATM System Demo (C++) ===\n\n";

    BankService bank;
    bank.add_account(std::make_unique<Account>("ACC1", "1234", 500));
    bank.add_account(std::make_unique<Account>("ACC2", "0000", 80));

    // Cash cassette via Chain of Responsibility (100 -> 50 -> 20 -> 10).
    auto chain = std::make_unique<HundredHandler>(5);
    chain->set_next(std::make_unique<FiftyHandler>(5))
         ->set_next(std::make_unique<TwentyHandler>(10))
         ->set_next(std::make_unique<TenHandler>(10));
    CashDispenser dispenser(std::move(chain));

    ATM atm(bank, dispenser);
    Card card("CARD-1001", "ACC1");

    // 1) Happy path: insert -> PIN -> withdraw -> balance -> eject.
    std::cout << "Scenario 1: successful withdrawal\n";
    atm.insert_card(card);
    atm.enter_pin("1234");
    WithdrawTransaction withdraw(*atm.current_account(), dispenser, 180);
    atm.perform_transaction(withdraw);
    BalanceInquiryTransaction inquiry(*atm.current_account());
    atm.perform_transaction(inquiry);
    atm.eject_card();

    // 2) Wrong PIN, then a correct retry, then a deposit.
    std::cout << "\nScenario 2: wrong PIN then retry\n";
    atm.insert_card(card);
    atm.enter_pin("0000"); // wrong
    atm.enter_pin("1234"); // correct
    DepositTransaction deposit(*atm.current_account(), 100);
    atm.perform_transaction(deposit);
    atm.eject_card();

    // 3) Withdrawal exceeding the account balance.
    std::cout << "\nScenario 3: insufficient account balance\n";
    Card card2("CARD-2002", "ACC2");
    atm.insert_card(card2);
    atm.enter_pin("0000");
    WithdrawTransaction over_withdraw(*atm.current_account(), dispenser, 200);
    atm.perform_transaction(over_withdraw);
    atm.eject_card();

    // 4) Acting without a card — the state refuses it.
    std::cout << "\nScenario 4: action without a card\n";
    atm.enter_pin("1234");

    return 0;
}
