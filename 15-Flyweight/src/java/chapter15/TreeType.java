package chapter15;

/**
 * Flyweight — stores ONLY intrinsic (shared) state: name, color, texture.
 * Immutable, so it can be safely shared by thousands of trees.
 * Extrinsic state (x, y) is passed IN via draw().
 */
public class TreeType {
    private final String name;
    private final String color;
    private final String texture;

    public TreeType(String name, String color, String texture) {
        this.name = name;
        this.color = color;
        this.texture = texture;
    }

    public void draw(int x, int y) {
        System.out.printf("  Drawing %s (%s, texture=%s) at (%d, %d)%n",
                name, color, texture, x, y);
    }

    public String getName() {
        return name;
    }
}
