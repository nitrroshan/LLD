package chapter09;

import java.util.ArrayList;
import java.util.List;

public abstract class Shape {
    protected int x;
    protected int y;
    protected String color;
    protected List<String> tags;

    public Shape(int x, int y, String color) {
        this.x = x;
        this.y = y;
        this.color = color;
        this.tags = new ArrayList<>();
    }

    // Copy constructor — deep copies mutable fields
    public Shape(Shape source) {
        this.x = source.x;
        this.y = source.y;
        this.color = source.color;                    // String is immutable — safe to share
        this.tags = new ArrayList<>(source.tags);     // deep copy the mutable list
    }

    public abstract Shape clone();

    public void addTag(String tag) {
        tags.add(tag);
    }

    public void moveTo(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return String.format("(%d,%d) color=%s tags=%s", x, y, color, tags);
    }
}
