package chapter24;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Template Method Pattern Demo ===\n");

        System.out.println("Making tea:");
        new Tea().prepareRecipe();

        System.out.println("\nMaking coffee:");
        new Coffee().prepareRecipe();

        System.out.println("\nMaking black coffee (hook skips condiments):");
        new BlackCoffee().prepareRecipe();

        System.out.println("\nEvery beverage followed the SAME fixed sequence —");
        System.out.println("only the brew and condiment steps varied.");
    }
}
