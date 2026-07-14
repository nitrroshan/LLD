#pragma once
#include <memory>
#include <vector>
#include <iostream>
#include "Command.h"

// Invoker — holds a command, triggers it, and records history for undo.
class RemoteControl {
    std::shared_ptr<Command> slot_;
    std::vector<std::shared_ptr<Command>> history_;

public:
    void set_command(std::shared_ptr<Command> command) {
        slot_ = std::move(command);
    }

    void press_button() {
        if (slot_) {
            slot_->execute();
            history_.push_back(slot_);
        }
    }

    void press_undo() {
        if (!history_.empty()) {
            std::cout << "  [undo]\n";
            history_.back()->undo();
            history_.pop_back();
        } else {
            std::cout << "  [undo] nothing to undo\n";
        }
    }
};
