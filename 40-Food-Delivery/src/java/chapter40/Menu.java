package chapter40;

import java.util.ArrayList;
import java.util.List;

/**
 * A restaurant's menu — a list of items.
 */
public class Menu {
    private final List<MenuItem> items = new ArrayList<>();

    public void addItem(MenuItem item) { items.add(item); }
    public List<MenuItem> items() { return items; }
}
