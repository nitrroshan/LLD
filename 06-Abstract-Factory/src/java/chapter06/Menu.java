package chapter06;

/**
 * Abstract Product — all menus must render and support selection.
 */
public interface Menu {
    void render();
    void select(String item);
}
