package chapter13;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Decorator Pattern Demo ===\n");

        // 1. Plain espresso — no decorators
        Coffee plain = new Espresso();
        printCoffee("Plain", plain);

        // 2. Espresso + Milk
        Coffee withMilk = new MilkDecorator(new Espresso());
        printCoffee("With milk", withMilk);

        // 3. Espresso + Milk + Whip + Caramel — stacked decorators
        Coffee loaded = new CaramelDecorator(
                            new WhipDecorator(
                                new MilkDecorator(
                                    new Espresso())));
        printCoffee("Loaded", loaded);

        // 4. Latte + Whip — different base, same decorators
        Coffee latteWhip = new WhipDecorator(new Latte());
        printCoffee("Latte+Whip", latteWhip);

        // 5. Double milk — same decorator applied twice
        Coffee doubleMilk = new MilkDecorator(
                                new MilkDecorator(
                                    new Espresso()));
        printCoffee("Double milk", doubleMilk);

        // 6. Dynamic decoration — build at runtime
        System.out.println("--- Dynamic Decoration ---");
        Coffee order = new Latte();
        System.out.println("  Start:    " + order.getDescription() + " $" + String.format("%.2f", order.getCost()));

        order = new MilkDecorator(order);
        System.out.println("  + Milk:   " + order.getDescription() + " $" + String.format("%.2f", order.getCost()));

        order = new CaramelDecorator(order);
        System.out.println("  + Caramel:" + order.getDescription() + " $" + String.format("%.2f", order.getCost()));
    }

    static void printCoffee(String label, Coffee coffee) {
        System.out.printf("  %-14s %s — $%.2f%n", label + ":", coffee.getDescription(), coffee.getCost());
    }
}
