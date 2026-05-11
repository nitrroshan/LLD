package chapter05;

/**
 * Concrete Creator — creates Truck transport.
 */
public class RoadLogistics extends LogisticsFactory {
    @Override
    public Transport createTransport() {
        return new Truck();
    }
}
