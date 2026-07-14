package chapter25;

/**
 * State — declares the actions whose behavior depends on the machine's state.
 */
public interface State {
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();
    String name();
}
