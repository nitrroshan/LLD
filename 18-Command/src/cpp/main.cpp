#include <iostream>
#include <memory>
#include <vector>
#include "Light.h"
#include "Command.h"
#include "LightOnCommand.h"
#include "LightOffCommand.h"
#include "MacroCommand.h"
#include "RemoteControl.h"

int main() {
    std::cout << "=== Command Pattern Demo (C++) ===\n\n";

    // Receivers
    Light living_room("Living Room");
    Light kitchen("Kitchen");

    // Concrete commands binding actions to receivers
    auto living_room_on = std::make_shared<LightOnCommand>(living_room);
    auto living_room_off = std::make_shared<LightOffCommand>(living_room);
    auto kitchen_on = std::make_shared<LightOnCommand>(kitchen);

    RemoteControl remote;

    std::cout << "Turn living room light on:\n";
    remote.set_command(living_room_on);
    remote.press_button();

    std::cout << "\nTurn it off:\n";
    remote.set_command(living_room_off);
    remote.press_button();

    std::cout << "\nUndo (should turn back on):\n";
    remote.press_undo();

    std::cout << "\nUndo again (should turn off):\n";
    remote.press_undo();

    // Macro command — "party mode"
    std::cout << "\n--- Macro Command: Party Mode ---\n";
    std::vector<std::shared_ptr<Command>> party = {living_room_on, kitchen_on};
    auto party_mode = std::make_shared<MacroCommand>(party);
    remote.set_command(party_mode);
    remote.press_button();

    std::cout << "\nUndo party mode (reverses both, in reverse order):\n";
    remote.press_undo();

    return 0;
}
