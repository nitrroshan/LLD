package chapter05;

/**
 * Client code — works with the Creator interface only.
 * Doesn't know or care whether it's using Truck, Ship, or Airplane.
 *
 * Compile & Run:
 *   cd 05-Factory-Method/src/java
 *   javac chapter05/*.java
 *   java chapter05.Main
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("=== Road Logistics ===");
        LogisticsFactory road = new RoadLogistics();
        road.planDelivery();

        System.out.println("\n=== Sea Logistics ===");
        LogisticsFactory sea = new SeaLogistics();
        sea.planDelivery();

        System.out.println("\n=== Air Logistics (added without changing existing code!) ===");
        LogisticsFactory air = new AirLogistics();
        air.planDelivery();

        // Polymorphism: loop through different factories
        System.out.println("\n=== All Logistics ===");
        LogisticsFactory[] factories = { road, sea, air };
        for (LogisticsFactory factory : factories) {
            factory.planDelivery();
        }
    }
}
