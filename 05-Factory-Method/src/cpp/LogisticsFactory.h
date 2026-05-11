#pragma once
#include <memory>
#include "Transport.h"

// Creator (abstract) — factory method + business logic
class LogisticsFactory {
public:
    virtual ~LogisticsFactory() = default;
    virtual std::unique_ptr<Transport> createTransport() const = 0;

    void planDelivery() const {
        auto transport = createTransport();
        std::cout << "Planning delivery with: " << transport->getName() << "\n";
        transport->deliver();
    }
};

// Concrete Creators
class RoadLogistics : public LogisticsFactory {
public:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Truck>();
    }
};

class SeaLogistics : public LogisticsFactory {
public:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Ship>();
    }
};

class AirLogistics : public LogisticsFactory {
public:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Airplane>();
    }
};
