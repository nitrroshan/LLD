package chapter05;

/**
 * Concrete Creator — creates Airplane transport.
 * Added WITHOUT modifying any existing code! (OCP)
 */
public class AirLogistics extends LogisticsFactory {
    @Override
    public Transport createTransport() {
        return new Airplane();
    }
}
