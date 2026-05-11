package chapter03;

/**
 * Run all SOLID principle demos.
 *
 * Compile & Run:
 *   cd 03-SOLID-Principles/src/java
 *   javac chapter03/*.java
 *   java chapter03.Main
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("╔══════════════════════════════════════╗");
        System.out.println("║   SOLID Principles — Chapter 03     ║");
        System.out.println("╚══════════════════════════════════════╝\n");

        System.out.println("━━━━━━ S — Single Responsibility ━━━━━━");
        SRP.main(args);

        System.out.println("\n━━━━━━ O — Open/Closed ━━━━━━");
        OCP.main(args);

        System.out.println("\n━━━━━━ L — Liskov Substitution ━━━━━━");
        LSP.main(args);

        System.out.println("\n━━━━━━ I — Interface Segregation ━━━━━━");
        ISP.main(args);

        System.out.println("\n━━━━━━ D — Dependency Inversion ━━━━━━");
        DIP.main(args);
    }
}
