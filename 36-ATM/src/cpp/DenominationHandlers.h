#pragma once
#include "DenominationHandler.h"

// Concrete note handlers — each fixes its denomination.
class HundredHandler : public DenominationHandler {
public:
    explicit HundredHandler(int notes) : DenominationHandler(100, notes) {}
};

class FiftyHandler : public DenominationHandler {
public:
    explicit FiftyHandler(int notes) : DenominationHandler(50, notes) {}
};

class TwentyHandler : public DenominationHandler {
public:
    explicit TwentyHandler(int notes) : DenominationHandler(20, notes) {}
};

class TenHandler : public DenominationHandler {
public:
    explicit TenHandler(int notes) : DenominationHandler(10, notes) {}
};
