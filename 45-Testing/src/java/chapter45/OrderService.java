package chapter45;

/**
 * The system under test. Its collaborators (gateway, clock) are INJECTED, so a
 * test can pass fakes — no real network, no wall clock, fully deterministic.
 */
public class OrderService {
    private final PaymentGateway gateway;
    private final Clock clock;

    public OrderService(PaymentGateway gateway, Clock clock) {
        this.gateway = gateway;
        this.clock = clock;
    }

    public Receipt checkout(double total) {
        long ts = clock.now();
        boolean paid = gateway.charge(total);
        return new Receipt(total, ts, paid);
    }
}
