package chapter35;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Vending Machine Demo ===\n");

        // Inventory (prices in cents).
        Inventory inventory = new Inventory();
        inventory.addProduct(new Product("A1", "Coke", 125), 2);
        inventory.addProduct(new Product("A2", "Water", 100), 1);
        inventory.addProduct(new Product("A3", "Chips", 75), 0);   // out of stock

        // Coin acceptor chain (Chain of Responsibility): nickel -> dime -> quarter -> dollar.
        CoinHandler coinChain = new NickelHandler();
        coinChain.setNext(new DimeHandler()).setNext(new QuarterHandler()).setNext(new DollarHandler());

        VendingMachine machine = new VendingMachine(inventory, coinChain);

        // 1) Cash purchase (State + Chain of Responsibility).
        System.out.println("Cash purchase of Water ($1.00):");
        machine.selectProduct("A2");
        machine.insertCoin(Coin.QUARTER);
        machine.insertCoin(Coin.PENNY);    // rejected by the chain
        machine.insertCoin(Coin.DOLLAR);   // now $1.25 >= $1.00 -> dispense + change

        // 2) Card purchase (State + Strategy).
        System.out.println("\nCard purchase of Coke ($1.25):");
        machine.selectProduct("A1");
        machine.payWith(new CardPaymentStrategy("1234567812349999"));

        // 3) Out of stock.
        System.out.println("\nTry to buy Chips (out of stock):");
        machine.selectProduct("A3");

        // 4) Cancel / refund.
        System.out.println("\nSelect Coke, insert a quarter, then cancel:");
        machine.selectProduct("A1");
        machine.insertCoin(Coin.QUARTER);
        machine.cancel();

        System.out.println("\nState machine + coin chain + payment strategy,");
        System.out.println("each pattern owning one concern.");
    }
}
