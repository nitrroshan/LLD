#include <iostream>
#include <string>
#include "TestSupport.h"
#include "OrderService.h"
#include "Targets.h"

int main() {
    std::cout << "=== Testing & Testable Design (C++) ===\n\n";
    TestSupport t;

    // 1) State test: checkout with a stubbed-success gateway + fixed clock.
    FakePaymentGateway ok_gateway(true);
    FixedClock clock(1000);
    OrderService service(ok_gateway, clock);
    Receipt receipt = service.checkout(250.0);
    t.assert_equals_double(250.0, receipt.total, "checkout returns the total");
    t.assert_equals<long>(1000, receipt.timestamp, "checkout uses the injected clock (deterministic)");
    t.assert_true(receipt.paid, "checkout is paid when the gateway succeeds");

    // 2) Interaction test: verify the gateway was charged once with the amount (spy).
    t.assert_equals<int>(1, ok_gateway.charge_count, "gateway charged exactly once");
    t.assert_equals_double(250.0, ok_gateway.last_amount, "gateway charged the correct amount");

    // 3) Failure path: a stubbed-failure gateway makes the order unpaid.
    FakePaymentGateway bad_gateway(false);
    OrderService failing(bad_gateway, clock);
    t.assert_true(!failing.checkout(99.0).paid, "checkout is unpaid when the gateway fails");

    // 4) Strategy test: pure and trivial.
    VipDiscount vip;
    t.assert_equals_double(40.0, vip.discount(200), "VIP discount is 20%");

    // 5) Observer interaction test with a spy (a lambda capturing counters).
    int count = 0;
    std::string last;
    EventSource source;
    source.add_observer([&](const std::string& e) { count++; last = e; });   // spy
    source.fire("saved");
    t.assert_equals<int>(1, count, "observer notified exactly once");
    t.assert_equals<std::string>("saved", last, "observer received the right payload");

    t.summary();
    return 0;
}
