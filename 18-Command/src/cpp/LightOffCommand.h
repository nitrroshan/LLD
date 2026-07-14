#pragma once
#include "Command.h"
#include "Light.h"

// Concrete Command — binds "turn off" to a Light; undo() turns it on.
class LightOffCommand : public Command {
    Light& light_;

public:
    explicit LightOffCommand(Light& light) : light_(light) {}

    void execute() override { light_.off(); }
    void undo() override { light_.on(); }
};
