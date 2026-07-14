package chapter32;

import java.util.HashMap;
import java.util.Map;

/**
 * The board: a size plus a map from a cell to the jump that starts there.
 */
public class Board {
    private final int size;
    private final Map<Integer, Jump> jumps = new HashMap<>();

    public Board(int size) {
        this.size = size;
    }

    public int getSize() {
        return size;
    }

    public void addJump(Jump jump) {
        jumps.put(jump.getStart(), jump);
    }

    /** Returns the jump starting at this cell, or null if there is none. */
    public Jump getJump(int cell) {
        return jumps.get(cell);
    }
}
