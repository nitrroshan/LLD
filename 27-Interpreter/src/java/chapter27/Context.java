package chapter27;

import java.util.HashMap;
import java.util.Map;

/**
 * Context — holds the external information interpretation needs. Here, the
 * boolean value bound to each variable name.
 */
public class Context {
    private final Map<String, Boolean> values = new HashMap<>();

    public void set(String name, boolean value) {
        values.put(name, value);
    }

    public boolean get(String name) {
        return values.getOrDefault(name, false);
    }
}
