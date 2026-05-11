package chapter01;

public class Rectangle implements Drawable {
    private double width;
    private double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public void draw() {
        System.out.println("Drawing Rectangle (" + width + " x " + height + ")");
    }

    @Override
    public double area() {
        return width * height;
    }
}
