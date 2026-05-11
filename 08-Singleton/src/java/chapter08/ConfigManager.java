package chapter08;

import java.util.HashMap;
import java.util.Map;

/**
 * Practical Singleton example: ConfigManager.
 * Loads configuration once, provides global access.
 */
public class ConfigManager {
    private final Map<String, String> properties;

    private ConfigManager() {
        properties = new HashMap<>();
        loadDefaults();
    }

    private static class Holder {
        private static final ConfigManager INSTANCE = new ConfigManager();
    }

    public static ConfigManager getInstance() {
        return Holder.INSTANCE;
    }

    private void loadDefaults() {
        properties.put("app.name", "LLD Learning App");
        properties.put("app.version", "1.0");
        properties.put("db.host", "localhost");
        properties.put("db.port", "5432");
        properties.put("log.level", "INFO");
    }

    public String get(String key) {
        return properties.getOrDefault(key, null);
    }

    public void set(String key, String value) {
        properties.put(key, value);
    }

    public int size() {
        return properties.size();
    }

    @Override
    public String toString() {
        return "ConfigManager[" + properties.size() + " properties]";
    }
}
