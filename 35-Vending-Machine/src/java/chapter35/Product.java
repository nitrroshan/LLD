package chapter35;

/**
 * A vendable item with a price in cents.
 */
public class Product {
    private final String code;
    private final String name;
    private final int priceCents;

    public Product(String code, String name, int priceCents) {
        this.code = code;
        this.name = name;
        this.priceCents = priceCents;
    }

    public String getCode() { return code; }
    public String getName() { return name; }
    public int getPriceCents() { return priceCents; }
}
