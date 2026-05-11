package chapter08;

import java.util.HashMap;
import java.util.Map;

/**
 * Practical Singleton example: DatabaseConnection.
 * Uses Bill Pugh approach (recommended).
 * Simulates a database connection pool — only one should exist.
 */
public class DatabaseConnection {
    private final String host;
    private final int port;
    private boolean connected;
    private final Map<String, String> connectionPool;

    private DatabaseConnection() {
        this.host = "localhost";
        this.port = 5432;
        this.connected = false;
        this.connectionPool = new HashMap<>();
    }

    private static class Holder {
        private static final DatabaseConnection INSTANCE = new DatabaseConnection();
    }

    public static DatabaseConnection getInstance() {
        return Holder.INSTANCE;
    }

    public void connect() {
        if (!connected) {
            connected = true;
            System.out.println("Connected to " + host + ":" + port);
        } else {
            System.out.println("Already connected to " + host + ":" + port);
        }
    }

    public void disconnect() {
        if (connected) {
            connected = false;
            connectionPool.clear();
            System.out.println("Disconnected from " + host + ":" + port);
        }
    }

    public String query(String sql) {
        if (!connected) {
            throw new IllegalStateException("Not connected — call connect() first");
        }
        return "Result of: " + sql;
    }

    public boolean isConnected() {
        return connected;
    }

    @Override
    public String toString() {
        return "DatabaseConnection[" + host + ":" + port +
               ", connected=" + connected + "]";
    }
}
