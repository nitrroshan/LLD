package chapter25.centralized;

/**
 * Same demo as the distributed version, but the machine here keeps ALL
 * transition logic centralized (the "context decides" approach).
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("=== State Pattern Demo (Centralized / context-decides) ===\n");

        GumballMachine machine = new GumballMachine(2);
        System.out.println(machine.status());

        System.out.println("\nBuy first gumball:");
        machine.insertQuarter();
        machine.turnCrank();
        System.out.println(machine.status());

        System.out.println("\nBuy second gumball (empties the machine):");
        machine.insertQuarter();
        machine.turnCrank();
        System.out.println(machine.status());

        System.out.println("\nTry to buy when sold out:");
        machine.insertQuarter();
        machine.turnCrank();

        System.out.println("\nSame behavior as the distributed version —");
        System.out.println("but every transition rule lives in the context, not in state objects.");
    }
}
