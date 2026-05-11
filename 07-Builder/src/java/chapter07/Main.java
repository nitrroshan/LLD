package chapter07;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Builder Pattern Demo ===\n");

        // 1. Build a custom house step by step
        House customHouse = new HouseBuilder()
                .rooms(4)
                .floors(2)
                .garage()
                .pool()
                .roofType("tile")
                .build();
        System.out.println("Custom:  " + customHouse);

        // 2. Use the Director for pre-defined configurations
        HouseDirector director = new HouseDirector();

        House luxury = director.buildLuxuryHouse(new HouseBuilder());
        System.out.println("Luxury:  " + luxury);

        House simple = director.buildSimpleHouse(new HouseBuilder());
        System.out.println("Simple:  " + simple);

        House family = director.buildFamilyHouse(new HouseBuilder());
        System.out.println("Family:  " + family);

        // 3. Minimal house — only defaults
        House minimal = new HouseBuilder().build();
        System.out.println("Minimal: " + minimal);
    }
}
