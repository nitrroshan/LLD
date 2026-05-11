package chapter05;

/**
 * Concrete Creator — creates Ship transport.
 */
public class SeaLogistics extends LogisticsFactory {
    @Override
    public Transport createTransport() {
        return new Ship();
    }
}
