package chapter15;

import java.util.ArrayList;
import java.util.List;

/**
 * Client — plants many trees. Each tree stores only its position;
 * the heavy shared data lives once per TreeType in the factory.
 */
public class Forest {
    private final List<Tree> trees = new ArrayList<>();
    private final TreeFactory factory = new TreeFactory();

    public void plantTree(int x, int y, String name, String color, String texture) {
        TreeType type = factory.getTreeType(name, color, texture);
        trees.add(new Tree(x, y, type));
    }

    public void draw() {
        for (Tree tree : trees) {
            tree.draw();
        }
    }

    public int treeCount() {
        return trees.size();
    }

    public int distinctTypeCount() {
        return factory.distinctTypeCount();
    }
}
