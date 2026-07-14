package chapter18;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Command Pattern Demo ===\n");

        // Receivers
        Light livingRoom = new Light("Living Room");
        Light kitchen = new Light("Kitchen");

        // Concrete commands binding actions to receivers
        Command livingRoomOn = new LightOnCommand(livingRoom);
        Command livingRoomOff = new LightOffCommand(livingRoom);
        Command kitchenOn = new LightOnCommand(kitchen);

        // Invoker
        RemoteControl remote = new RemoteControl();

        System.out.println("Turn living room light on:");
        remote.setCommand(livingRoomOn);
        remote.pressButton();

        System.out.println("\nTurn it off:");
        remote.setCommand(livingRoomOff);
        remote.pressButton();

        System.out.println("\nUndo (should turn back on):");
        remote.pressUndo();

        System.out.println("\nUndo again (should turn off):");
        remote.pressUndo();

        // Macro command — "party mode": both lights on at once
        System.out.println("\n--- Macro Command: Party Mode ---");
        Command partyMode = new MacroCommand(List.of(livingRoomOn, kitchenOn));
        remote.setCommand(partyMode);
        remote.pressButton();

        System.out.println("\nUndo party mode (reverses both, in reverse order):");
        remote.pressUndo();
    }
}
