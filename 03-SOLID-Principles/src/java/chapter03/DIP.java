package chapter03;

/**
 * DIP — Dependency Inversion Principle
 *
 * BAD:  OrderService directly creates and depends on MySQLDatabase.
 * GOOD: OrderService depends on a Database interface, implementation is injected.
 */
public class DIP {

    // ===================== BAD =====================
    static class MySQLDatabase {
        void save(String data) {
            System.out.println("[MySQL] Saved: " + data);
        }
    }

    static class OrderServiceBad {
        private MySQLDatabase db = new MySQLDatabase();  // hardcoded!

        void placeOrder(String order) {
            System.out.println("Placing order: " + order);
            db.save(order);
            // Want to switch to PostgreSQL? Must rewrite this class!
        }
    }

    // ===================== GOOD =====================
    interface Database {
        void save(String data);
    }

    static class MySQL implements Database {
        public void save(String data) {
            System.out.println("[MySQL] Saved: " + data);
        }
    }

    static class PostgreSQL implements Database {
        public void save(String data) {
            System.out.println("[PostgreSQL] Saved: " + data);
        }
    }

    static class InMemoryDatabase implements Database {
        public void save(String data) {
            System.out.println("[InMemory] Saved: " + data);
        }
    }

    static class OrderService {
        private Database db;  // depends on abstraction!

        OrderService(Database db) {  // injected via constructor
            this.db = db;
        }

        void placeOrder(String order) {
            System.out.println("Placing order: " + order);
            db.save(order);
        }
    }

    // ===================== DEMO =====================
    public static void main(String[] args) {
        System.out.println("=== BAD (hardcoded MySQL dependency) ===");
        OrderServiceBad bad = new OrderServiceBad();
        bad.placeOrder("Laptop");

        System.out.println("\n=== GOOD (injected database — easily swappable) ===");
        OrderService withMySQL = new OrderService(new MySQL());
        withMySQL.placeOrder("Laptop");

        OrderService withPostgres = new OrderService(new PostgreSQL());
        withPostgres.placeOrder("Phone");

        OrderService withInMemory = new OrderService(new InMemoryDatabase());
        withInMemory.placeOrder("Tablet");  // great for testing!
    }
}
