package chapter15;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Flyweight Pattern Demo ===\n");

        Forest forest = new Forest();

        // Plant 1,000,000 trees, but only 3 distinct types
        System.out.println("Planting 1,000,000 trees...");
        String[][] species = {
            {"Oak", "Green", "oak.png"},
            {"Pine", "DarkGreen", "pine.png"},
            {"Cherry", "Pink", "cherry.png"},
        };

        for (int i = 0; i < 1_000_000; i++) {
            String[] s = species[i % species.length];
            forest.plantTree(i % 800, i % 600, s[0], s[1], s[2]);
        }

        System.out.println("\nResult:");
        System.out.println("  Trees planted:        " + forest.treeCount());
        System.out.println("  Distinct TreeTypes:   " + forest.distinctTypeCount());
        System.out.println("  Memory saved: 1,000,000 contexts share only "
                + forest.distinctTypeCount() + " heavy flyweight objects.");

        // Draw a few sample trees to show extrinsic state passed in
        System.out.println("\n--- Sample draws (first 3 trees) ---");
        Forest sample = new Forest();
        sample.plantTree(10, 20, "Oak", "Green", "oak.png");
        sample.plantTree(35, 40, "Pine", "DarkGreen", "pine.png");
        sample.plantTree(50, 12, "Oak", "Green", "oak.png");  // reuses the Oak flyweight
        sample.draw();
    }
}
