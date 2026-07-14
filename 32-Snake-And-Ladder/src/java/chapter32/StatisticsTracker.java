package chapter32;

/**
 * Concrete Observer — tracks aggregate statistics without printing per turn.
 * Demonstrates that multiple observers can react to the same events.
 */
public class StatisticsTracker implements GameEventListener {
    private int totalMoves;
    private int snakesHit;
    private int laddersClimbed;

    @Override
    public void onMove(Player player, int from, int to, int diceValue) {
        totalMoves++;
    }

    @Override
    public void onJump(Player player, JumpType type, int from, int to) {
        if (type == JumpType.SNAKE) {
            snakesHit++;
        } else {
            laddersClimbed++;
        }
    }

    @Override
    public void onSkip(Player player, int diceValue) {
        // counted as a turn but not a move
    }

    @Override
    public void onWin(Player player) {
        System.out.println("  --- Stats ---");
        System.out.println("    Total moves:      " + totalMoves);
        System.out.println("    Ladders climbed:  " + laddersClimbed);
        System.out.println("    Snakes hit:       " + snakesHit);
    }
}
