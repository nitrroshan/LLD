package chapter09;

public class Circle extends Shape {
    private int radius;

    public Circle(int x, int y, String color, int radius) {
        super(x, y, color);
        this.radius = radius;
    }

    // Copy constructor
    public Circle(Circle source) {
        super(source);                 // copies x, y, color, tags (deep)
        this.radius = source.radius;   // primitive — copied by value
    }

    @Override
    public Circle clone() {
        return new Circle(this);
    }

    public int getRadius() {
        return radius;
    }

    @Override
    public String toString() {
        return "Circle [radius=" + radius + " " + super.toString() + "]";
    }
}
