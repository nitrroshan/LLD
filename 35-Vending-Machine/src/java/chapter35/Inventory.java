package chapter35;

import java.util.HashMap;
import java.util.Map;

/**
 * Products keyed by slot code, with per-slot stock counts.
 */
public class Inventory {
    private final Map<String, Product> products = new HashMap<>();
    private final Map<String, Integer> stock = new HashMap<>();

    public void addProduct(Product product, int quantity) {
        products.put(product.getCode(), product);
        stock.put(product.getCode(), quantity);
    }

    public Product getProduct(String code) {
        return products.get(code);
    }

    public boolean isInStock(String code) {
        return stock.getOrDefault(code, 0) > 0;
    }

    public void reduceStock(String code) {
        stock.put(code, stock.getOrDefault(code, 0) - 1);
    }

    public int getStock(String code) {
        return stock.getOrDefault(code, 0);
    }
}
