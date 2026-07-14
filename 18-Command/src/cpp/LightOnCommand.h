#pragma once
#include "Command.h"
#include "Light.h"

// Concrete Command — binds "turn on" to a Light; undo() turns it off.
class LightOnCommand : public Command {
    Light& light_;

public:
    explicit LightOnCommand(Light& light) : light_(light) {}

    void execute() override { light_.on(); }
    void undo() override { light_.off(); }
};
