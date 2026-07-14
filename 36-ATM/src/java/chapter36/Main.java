package chapter36;

/**
 * Demo — drives the ATM through its states with transactions as commands and
 * cash dispensed via the denomination chain.
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("=== ATM System Demo (Java) ===\n");

        BankService bank = new BankService();
        bank.addAccount(new Account("ACC1", "1234", 500));
        bank.addAccount(new Account("ACC2", "0000", 80));

        // Cash cassette via Chain of Responsibility (100 -> 50 -> 20 -> 10).
        DenominationHandler chain = new HundredHandler(5);
        chain.setNext(new FiftyHandler(5))
             .setNext(new TwentyHandler(10))
             .setNext(new TenHandler(10));
        CashDispenser dispenser = new CashDispenser(chain);

        ATM atm = new ATM(bank, dispenser);
        Card card = new Card("CARD-1001", "ACC1");

        // 1) Happy path: insert -> PIN -> withdraw -> balance -> eject.
        System.out.println("Scenario 1: successful withdrawal");
        atm.insertCard(card);
        atm.enterPin("1234");
        atm.performTransaction(new WithdrawTransaction(atm.getCurrentAccount(), dispenser, 180));
        atm.performTransaction(new BalanceInquiryTransaction(atm.getCurrentAccount()));
        atm.ejectCard();

        // 2) Wrong PIN, then a correct retry, then a deposit.
        System.out.println("\nScenario 2: wrong PIN then retry");
        atm.insertCard(card);
        atm.enterPin("0000"); // wrong
        atm.enterPin("1234"); // correct
        atm.performTransaction(new DepositTransaction(atm.getCurrentAccount(), 100));
        atm.ejectCard();

        // 3) Withdrawal exceeding the account balance.
        System.out.println("\nScenario 3: insufficient account balance");
        Card card2 = new Card("CARD-2002", "ACC2");
        atm.insertCard(card2);
        atm.enterPin("0000");
        atm.performTransaction(new WithdrawTransaction(atm.getCurrentAccount(), dispenser, 200));
        atm.ejectCard();

        // 4) Acting without a card — the state refuses it.
        System.out.println("\nScenario 4: action without a card");
        atm.enterPin("1234");
    }
}
