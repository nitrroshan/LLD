package chapter15;

import java.util.HashMap;
import java.util.Map;

/**
 * Flyweight Factory — creates and caches TreeType flyweights.
 * Identical intrinsic state is never duplicated: the same combination
 * of name/color/texture always returns the SAME shared instance.
 */
public class TreeFactory {
    private final Map<String, TreeType> cache = new HashMap<>();

    public TreeType getTreeType(String name, String color, String texture) {
        String key = name + "-" + color + "-" + texture;
        return cache.computeIfAbsent(key, k -> {
            System.out.println("  [Factory] Creating new TreeType: " + key);
            return new TreeType(name, color, texture);
        });
    }

    public int distinctTypeCount() {
        return cache.size();
    }
}
