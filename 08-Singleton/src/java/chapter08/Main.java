package chapter08;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Singleton Pattern Demo ===\n");

        // 1. Eager Singleton
        System.out.println("--- Eager Singleton ---");
        EagerSingleton eager1 = EagerSingleton.getInstance();
        EagerSingleton eager2 = EagerSingleton.getInstance();
        eager1.doSomething();
        eager2.doSomething();
        System.out.println("Same instance? " + (eager1 == eager2));
        System.out.println();

        // 2. Bill Pugh Singleton
        System.out.println("--- Bill Pugh Singleton ---");
        BillPughSingleton bp1 = BillPughSingleton.getInstance();
        BillPughSingleton bp2 = BillPughSingleton.getInstance();
        bp1.doSomething();
        bp2.doSomething();
        System.out.println("Same instance? " + (bp1 == bp2));
        System.out.println();

        // 3. Thread-Safe (Double-Checked Locking)
        System.out.println("--- Thread-Safe Singleton ---");
        ThreadSafeSingleton ts1 = ThreadSafeSingleton.getInstance();
        ThreadSafeSingleton ts2 = ThreadSafeSingleton.getInstance();
        ts1.doSomething();
        ts2.doSomething();
        System.out.println("Same instance? " + (ts1 == ts2));
        System.out.println();

        // 4. Enum Singleton
        System.out.println("--- Enum Singleton ---");
        EnumSingleton.INSTANCE.doSomething();
        EnumSingleton.INSTANCE.doSomething();
        EnumSingleton.INSTANCE.doSomething();
        System.out.println();

        // 5. Practical: DatabaseConnection
        System.out.println("--- DatabaseConnection Singleton ---");
        DatabaseConnection db1 = DatabaseConnection.getInstance();
        DatabaseConnection db2 = DatabaseConnection.getInstance();
        System.out.println("Same instance? " + (db1 == db2));
        db1.connect();
        db2.connect(); // Already connected — same instance!
        System.out.println(db1.query("SELECT * FROM users"));
        db1.disconnect();
        System.out.println();

        // 6. Practical: ConfigManager
        System.out.println("--- ConfigManager Singleton ---");
        ConfigManager config1 = ConfigManager.getInstance();
        ConfigManager config2 = ConfigManager.getInstance();
        System.out.println("Same instance? " + (config1 == config2));
        System.out.println("app.name = " + config1.get("app.name"));
        config1.set("app.name", "Updated App");
        System.out.println("app.name (via config2) = " + config2.get("app.name"));
        // Both references see the change — they're the same object
    }
}
