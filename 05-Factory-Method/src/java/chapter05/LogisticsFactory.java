package chapter05;

/**
 * Creator (abstract) — defines the factory method + business logic.
 *
 * Key: planDelivery() uses createTransport() without knowing the concrete type.
 * This is Factory Method + Template Method combined.
 */
public abstract class LogisticsFactory {

    // Factory method — subclasses decide which Transport to create
    public abstract Transport createTransport();

    // Business logic that USES the product
    public void planDelivery() {
        Transport transport = createTransport();
        System.out.println("Planning delivery with: " + transport.getName());
        transport.deliver();
    }
}
