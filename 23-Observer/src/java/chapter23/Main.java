package chapter23;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Observer Pattern Demo ===\n");

        WeatherStation station = new WeatherStation();

        Observer alicePhone = new PhoneDisplay("Alice");
        Observer bobPhone = new PhoneDisplay("Bob");
        Observer window = new WindowDisplay();

        // Subscribe observers
        station.registerObserver(alicePhone);
        station.registerObserver(bobPhone);
        station.registerObserver(window);

        // One change → everyone is notified automatically
        station.setTemperature(22.5f);

        System.out.println();
        station.setTemperature(28.0f);

        // Unsubscribe at runtime — Bob stops receiving updates
        System.out.println("\nBob unsubscribes...");
        station.removeObserver(bobPhone);

        System.out.println();
        station.setTemperature(19.0f);

        System.out.println("\nThe station never referenced a concrete display —");
        System.out.println("it only pushed updates to the Observer list.");
    }
}
