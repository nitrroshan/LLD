#pragma once
#include "CoinHandler.h"

class NickelHandler : public CoinHandler {
protected:
    bool can_handle(Coin coin) const override { return coin == Coin::Nickel; }
};

class DimeHandler : public CoinHandler {
protected:
    bool can_handle(Coin coin) const override { return coin == Coin::Dime; }
};

class QuarterHandler : public CoinHandler {
protected:
    bool can_handle(Coin coin) const override { return coin == Coin::Quarter; }
};

class DollarHandler : public CoinHandler {
protected:
    bool can_handle(Coin coin) const override { return coin == Coin::Dollar; }
};
