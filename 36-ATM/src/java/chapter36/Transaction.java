package chapter36;

/**
 * Command — a transaction encapsulated as an object with execute(). The ATM
 * invokes them uniformly, so new transaction types are additive and auditable.
 */
public interface Transaction {
    void execute();
    String description();
}
