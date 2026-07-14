package chapter32;

import java.util.ArrayList;
import java.util.List;

/**
 * Runs the game: rotates players, rolls the die, applies jumps, and emits
 * events to observers until someone lands exactly on the final cell.
 */
public class Game {
    private final Board board;
    private final Dice dice;
    private final List<Player> players;
    private final List<GameEventListener> listeners = new ArrayList<>();
    private int currentPlayer = 0;
    private GameStatus status = GameStatus.RUNNING;

    public Game(Board board, Dice dice, List<Player> players) {
        this.board = board;
        this.dice = dice;
        this.players = players;
    }

    public void addListener(GameEventListener listener) {
        listeners.add(listener);
    }

    public GameStatus getStatus() {
        return status;
    }

    public void playTurn() {
        Player player = players.get(currentPlayer);
        int dice = this.dice.roll();
        int from = player.getPosition();
        int target = from + dice;

        if (target > board.getSize()) {
            notifySkip(player, dice);
        } else {
            Jump jump = board.getJump(target);
            int destination = (jump != null) ? jump.getEnd() : target;
            player.setPosition(destination);
            notifyMove(player, from, target, dice);
            if (jump != null) {
                notifyJump(player, jump.getType(), target, destination);
            }
            if (destination == board.getSize()) {
                notifyWin(player);
                status = GameStatus.FINISHED;
                return;
            }
        }
        currentPlayer = (currentPlayer + 1) % players.size();
    }

    /** Play until someone wins, with a safety cap on turns. */
    public void play(int maxTurns) {
        int turn = 0;
        while (status == GameStatus.RUNNING && turn < maxTurns) {
            playTurn();
            turn++;
        }
    }

    private void notifyMove(Player p, int from, int to, int dice) {
        for (GameEventListener l : listeners) l.onMove(p, from, to, dice);
    }

    private void notifyJump(Player p, JumpType type, int from, int to) {
        for (GameEventListener l : listeners) l.onJump(p, type, from, to);
    }

    private void notifySkip(Player p, int dice) {
        for (GameEventListener l : listeners) l.onSkip(p, dice);
    }

    private void notifyWin(Player p) {
        for (GameEventListener l : listeners) l.onWin(p);
    }
}
