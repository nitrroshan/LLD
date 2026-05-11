package chapter09;

import java.util.HashMap;
import java.util.Map;

public class ShapeRegistry {
    private final Map<String, Shape> prototypes = new HashMap<>();

    public void register(String key, Shape shape) {
        prototypes.put(key, shape);
    }

    public Shape get(String key) {
        Shape prototype = prototypes.get(key);
        if (prototype == null) {
            throw new IllegalArgumentException("Unknown prototype: " + key);
        }
        return prototype.clone();  // always return a CLONE, never the original
    }

    public boolean contains(String key) {
        return prototypes.containsKey(key);
    }

    public int size() {
        return prototypes.size();
    }
}
