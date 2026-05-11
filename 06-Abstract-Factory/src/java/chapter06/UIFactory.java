package chapter06;

/**
 * Abstract Factory — declares creation methods for each product in the family.
 * Each concrete factory creates a CONSISTENT set of products.
 */
public interface UIFactory {
    Button createButton();
    Checkbox createCheckbox();
    Menu createMenu();
}
