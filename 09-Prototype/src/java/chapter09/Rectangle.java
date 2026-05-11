package chapter09;

public class Rectangle extends Shape {
    private int width;
    private int height;

    public Rectangle(int x, int y, String color, int width, int height) {
        super(x, y, color);
        this.width = width;
        this.height = height;
    }

    // Copy constructor
    public Rectangle(Rectangle source) {
        super(source);
        this.width = source.width;
        this.height = source.height;
    }

    @Override
    public Rectangle clone() {
        return new Rectangle(this);
    }

    public int getWidth() { return width; }
    public int getHeight() { return height; }

    @Override
    public String toString() {
        return "Rectangle [" + width + "x" + height + " " + super.toString() + "]";
    }
}
