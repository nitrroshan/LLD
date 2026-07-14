#pragma once
#include <vector>
#include <memory>
#include "Command.h"

// Macro Command — groups commands (Command + Composite). undo() reverses
// them in REVERSE order so state unwinds correctly.
class MacroCommand : public Command {
    std::vector<std::shared_ptr<Command>> commands_;

public:
    explicit MacroCommand(std::vector<std::shared_ptr<Command>> commands)
        : commands_(std::move(commands)) {}

    void execute() override {
        for (auto& command : commands_) {
            command->execute();
        }
    }

    void undo() override {
        for (auto it = commands_.rbegin(); it != commands_.rend(); ++it) {
            (*it)->undo();
        }
    }
};
