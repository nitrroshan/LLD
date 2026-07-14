package chapter32;

/**
 * Observer — reacts to game events. The game notifies all listeners without
 * knowing what they do (log, count, record, display).
 */
public interface GameEventListener {
    void onMove(Player player, int from, int to, int diceValue);
    void onJump(Player player, JumpType type, int from, int to);
    void onSkip(Player player, int diceValue);
    void onWin(Player player);
}
