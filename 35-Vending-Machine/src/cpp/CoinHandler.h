#pragma once
#include <memory>
#include "Coin.h"

// Chain of Responsibility — a coin acceptor link. Each handler accepts one
// denomination (returning its value) or forwards to the next. If none accept,
// handle() returns 0 (coin rejected).
class CoinHandler {
protected:
    std::unique_ptr<CoinHandler> next_;

    virtual bool can_handle(Coin coin) const = 0;

public:
    virtual ~CoinHandler() = default;

    CoinHandler* set_next(std::unique_ptr<CoinHandler> next) {
        next_ = std::move(next);
        return next_.get();
    }

    int handle(Coin coin) const {
        if (can_handle(coin)) {
            return value_of(coin);
        }
        if (next_) {
            return next_->handle(coin);
        }
        return 0;
    }
};
