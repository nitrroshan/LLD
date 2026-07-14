package chapter39;

/**
 * A 2D location. Distance is Euclidean "km" for a deterministic demo (a real
 * system would use haversine over lat/lng, or road ETA from a routing service).
 */
public final class Location {
    private final double x;
    private final double y;

    public Location(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double x() { return x; }
    public double y() { return y; }

    public double distanceTo(Location other) {
        double dx = x - other.x;
        double dy = y - other.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    @Override
    public String toString() {
        return "(" + x + "," + y + ")";
    }
}
