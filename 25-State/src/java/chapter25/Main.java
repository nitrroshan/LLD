package chapter25;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== State Pattern Demo ===\n");

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

        System.out.println("\nSame actions behaved differently in each state —");
        System.out.println("no conditionals, just the current State object.");
    }
}
