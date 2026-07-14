package chapter15;

/**
 * Context — stores extrinsic (unique) state: x, y.
 * Holds a reference to a shared TreeType flyweight instead of duplicating it.
 */
public class Tree {
    private final int x;
    private final int y;
    private final TreeType type;

    public Tree(int x, int y, TreeType type) {
        this.x = x;
        this.y = y;
        this.type = type;
    }

    public void draw() {
        type.draw(x, y);
    }
}
