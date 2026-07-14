#pragma once

// A payment gateway abstraction — the seam that makes OrderService testable.
class PaymentGateway {
public:
    virtual ~PaymentGateway() = default;
    virtual bool charge(double amount) = 0;
};

// A test double: a STUB (canned result) that is also a SPY (records the call).
class FakePaymentGateway : public PaymentGateway {
    bool result_;
public:
    int charge_count = 0;
    double last_amount = -1;

    explicit FakePaymentGateway(bool result) : result_(result) {}

    bool charge(double amount) override {
        charge_count++;        // spy: record the call
        last_amount = amount;
        return result_;        // stub: canned answer, no real network
    }
};

// Time as an injected abstraction — deterministic in tests.
class Clock {
public:
    virtual ~Clock() = default;
    virtual long now() const = 0;
};

class FixedClock : public Clock {
    long fixed_;
public:
    explicit FixedClock(long fixed) : fixed_(fixed) {}
    long now() const override { return fixed_; }
};

struct Receipt {
    double total;
    long timestamp;
    bool paid;
};

// The system under test — collaborators are INJECTED (by reference).
class OrderService {
    PaymentGateway& gateway_;
    Clock& clock_;
public:
    OrderService(PaymentGateway& gateway, Clock& clock) : gateway_(gateway), clock_(clock) {}

    Receipt checkout(double total) {
        long ts = clock_.now();
        bool paid = gateway_.charge(total);
        return Receipt{total, ts, paid};
    }
};
