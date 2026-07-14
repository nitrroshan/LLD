package chapter16;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Proxy Pattern Demo (Virtual / Lazy Loading) ===\n");

        // Creating the proxies is cheap — no disk load happens here
        System.out.println("Creating image proxies (no loading expected):");
        Image photo1 = new ProxyImage("vacation.jpg");
        Image photo2 = new ProxyImage("portrait.jpg");

        // The heavy load happens only when display() is first called
        System.out.println("\nFirst display of photo1 (triggers load):");
        photo1.display();

        System.out.println("\nSecond display of photo1 (already loaded, no reload):");
        photo1.display();

        System.out.println("\nphoto2 was never displayed — so it was never loaded.");
        System.out.println("That is the point of a virtual proxy: pay the cost only if used.");
    }
}
