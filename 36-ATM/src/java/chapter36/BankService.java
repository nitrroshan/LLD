package chapter36;

import java.util.HashMap;
import java.util.Map;

/**
 * The bank behind the ATM. Owns accounts and authenticates a card + PIN.
 * Keeping balances here (not in the ATM) makes the ATM a thin terminal.
 */
public class BankService {
    private final Map<String, Account> accounts = new HashMap<>();

    public void addAccount(Account account) {
        accounts.put(account.getAccountNumber(), account);
    }

    /** Returns the account if the card maps to it and the PIN matches, else null. */
    public Account authenticate(Card card, String pin) {
        Account account = accounts.get(card.getAccountNumber());
        if (account != null && account.verifyPin(pin)) {
            return account;
        }
        return null;
    }

    public Account getAccount(String accountNumber) {
        return accounts.get(accountNumber);
    }
}
