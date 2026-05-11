package chapter01;

/**
 * Demonstrates all 4 OOP pillars with an Animal hierarchy.
 * Run this file to see encapsulation, inheritance, polymorphism, and abstraction in action.
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("=== ENCAPSULATION ===");
        BankAccount account = new BankAccount("Alice", 1000);
        account.deposit(500);
        account.withdraw(200);
        account.withdraw(5000);  // should fail
        System.out.println("Balance: " + account.getBalance());

        System.out.println("\n=== INHERITANCE & POLYMORPHISM ===");
        Animal[] animals = {
            new Dog("Buddy", "Golden Retriever"),
            new Cat("Whiskers"),
            new Dog("Rex", "German Shepherd")
        };

        for (Animal animal : animals) {
            animal.eat();
            animal.makeSound();  // runtime polymorphism — each animal sounds different
            System.out.println();
        }

        System.out.println("=== ABSTRACTION (Interface) ===");
        Drawable[] drawables = { new Circle(5), new Rectangle(4, 6) };
        for (Drawable d : drawables) {
            d.draw();
            System.out.println("Area: " + d.area());
            System.out.println();
        }

        System.out.println("=== OVERLOADING (Compile-time Polymorphism) ===");
        Calculator calc = new Calculator();
        System.out.println("add(2, 3)       = " + calc.add(2, 3));
        System.out.println("add(2.5, 3.5)   = " + calc.add(2.5, 3.5));
        System.out.println("add(1, 2, 3)    = " + calc.add(1, 2, 3));
    }
}
