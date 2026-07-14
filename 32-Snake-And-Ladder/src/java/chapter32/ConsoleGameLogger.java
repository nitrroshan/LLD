package chapter32;

/**
 * Concrete Observer — prints a play-by-play of the game.
 */
public class ConsoleGameLogger implements GameEventListener {
    @Override
    public void onMove(Player player, int from, int to, int diceValue) {
        System.out.printf("  %s rolled %d: %d -> %d%n", player.getName(), diceValue, from, to);
    }

    @Override
    public void onJump(Player player, JumpType type, int from, int to) {
        if (type == JumpType.LADDER) {
            System.out.printf("    Ladder! %s climbs %d -> %d%n", player.getName(), from, to);
        } else {
            System.out.printf("    Snake! %s slides %d -> %d%n", player.getName(), from, to);
        }
    }

    @Override
    public void onSkip(Player player, int diceValue) {
        System.out.printf("  %s rolled %d but would overshoot — stays put%n", player.getName(), diceValue);
    }

    @Override
    public void onWin(Player player) {
        System.out.printf("  %s reached the final cell and WINS!%n", player.getName());
    }
}
