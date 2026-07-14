package chapter45;

/**
 * The runnable "test suite" — hand-rolled tests that demonstrate testable design:
 *  - injecting fakes (stub + spy gateway, fixed clock) into OrderService
 *  - verifying an interaction (charge called once with the right amount)
 *  - testing a Strategy directly
 *  - testing Observer notifications with a spy
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("=== Testing & Testable Design (Java) ===\n");
        TestSupport t = new TestSupport();

        // 1) State test: checkout with a stubbed-success gateway + fixed clock.
        FakePaymentGateway okGateway = new FakePaymentGateway(true);
        OrderService service = new OrderService(okGateway, new FixedClock(1000));
        Receipt receipt = service.checkout(250.0);
        t.assertEqualsDouble(250.0, receipt.total, "checkout returns the total");
        t.assertEquals(1000L, receipt.timestamp, "checkout uses the injected clock (deterministic)");
        t.assertTrue(receipt.paid, "checkout is paid when the gateway succeeds");

        // 2) Interaction test: verify the gateway was charged once with the amount (spy).
        t.assertEquals(1, okGateway.chargeCount, "gateway charged exactly once");
        t.assertEqualsDouble(250.0, okGateway.lastAmount, "gateway charged the correct amount");

        // 3) Failure path: a stubbed-failure gateway makes the order unpaid.
        OrderService failing = new OrderService(new FakePaymentGateway(false), new FixedClock(1000));
        t.assertTrue(!failing.checkout(99.0).paid, "checkout is unpaid when the gateway fails");

        // 4) Strategy test: pure and trivial.
        t.assertEqualsDouble(40.0, new VipDiscount().discount(200), "VIP discount is 20%");
        // ...with a stub strategy injected as a lambda:
        DiscountStrategy fixedTen = subtotal -> 10.0;
        t.assertEqualsDouble(10.0, fixedTen.discount(999), "stub strategy returns a fixed value");

        // 5) Observer interaction test with a spy.
        int[] count = {0};
        String[] last = {null};
        EventSource source = new EventSource();
        source.addObserver(event -> { count[0]++; last[0] = event; });   // spy
        source.fire("saved");
        t.assertEquals(1, count[0], "observer notified exactly once");
        t.assertEquals("saved", last[0], "observer received the right payload");

        t.summary();
    }
}
