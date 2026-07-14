#pragma once
#include <memory>
#include <algorithm>
#include <iostream>

// Chain of Responsibility — one handler per note denomination. Each handler
// takes as many of its note as it can and forwards the remainder to the next.
class DenominationHandler {
protected:
    int denomination_;
    int available_notes_;
    std::unique_ptr<DenominationHandler> next_;

public:
    DenominationHandler(int denomination, int available_notes)
        : denomination_(denomination), available_notes_(available_notes) {}
    virtual ~DenominationHandler() = default;

    // Wire the next handler; returns a raw pointer to it for fluent chaining.
    DenominationHandler* set_next(std::unique_ptr<DenominationHandler> next) {
        next_ = std::move(next);
        return next_.get();
    }

    // Total cash held from this handler onward.
    int total_cash() const {
        int mine = denomination_ * available_notes_;
        return next_ ? mine + next_->total_cash() : mine;
    }

    // Simulate greedily WITHOUT mutating counts — can this amount be made exactly?
    bool can_dispense(int amount) const {
        int use = std::min(amount / denomination_, available_notes_);
        int remaining = amount - use * denomination_;
        if (remaining == 0) {
            return true;
        }
        return next_ && next_->can_dispense(remaining);
    }

    // Actually dispense greedily, mutating counts. Assumes can_dispense was true.
    void dispense(int amount) {
        int use = std::min(amount / denomination_, available_notes_);
        if (use > 0) {
            available_notes_ -= use;
            std::cout << "    Dispensing " << use << " x $" << denomination_ << "\n";
        }
        int remaining = amount - use * denomination_;
        if (remaining > 0 && next_) {
            next_->dispense(remaining);
        }
    }
};
