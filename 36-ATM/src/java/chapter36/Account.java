package chapter36;

/**
 * An account held by the bank. Owns the balance and verifies its own PIN.
 */
public class Account {
    private final String accountNumber;
    private final String pin;
    private int balance; // whole dollars

    public Account(String accountNumber, String pin, int balance) {
        this.accountNumber = accountNumber;
        this.pin = pin;
        this.balance = balance;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public boolean verifyPin(String candidate) {
        return pin.equals(candidate);
    }

    public int getBalance() {
        return balance;
    }

    public void debit(int amount) {
        balance -= amount;
    }

    public void credit(int amount) {
        balance += amount;
    }
}
