package chapter31;

import java.util.ArrayList;
import java.util.List;

/**
 * An N×N board. Detects a winner (full row / column / diagonal of one symbol),
 * lists available moves, and can be copied for AI look-ahead.
 */
public class Board {
    private final int size;
    private final Symbol[][] grid;

    public Board(int size) {
        this.size = size;
        this.grid = new Symbol[size][size];
        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                grid[r][c] = Symbol.EMPTY;
            }
        }
    }

    public int getSize() { return size; }

    public Symbol get(int row, int col) {
        return grid[row][col];
    }

    public boolean isValid(Move move) {
        int r = move.getRow();
        int c = move.getCol();
        return r >= 0 && r < size && c >= 0 && c < size && grid[r][c] == Symbol.EMPTY;
    }

    public void placeMark(Move move, Symbol symbol) {
        grid[move.getRow()][move.getCol()] = symbol;
    }

    public List<Move> availableMoves() {
        List<Move> moves = new ArrayList<>();
        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                if (grid[r][c] == Symbol.EMPTY) {
                    moves.add(new Move(r, c));
                }
            }
        }
        return moves;
    }

    public boolean isFull() {
        return availableMoves().isEmpty();
    }

    /** Returns the winning symbol, or EMPTY if there is no winner yet. */
    public Symbol getWinner() {
        // Rows and columns
        for (int i = 0; i < size; i++) {
            Symbol row = lineWinner(i, 0, 0, 1);
            if (row != Symbol.EMPTY) return row;
            Symbol col = lineWinner(0, i, 1, 0);
            if (col != Symbol.EMPTY) return col;
        }
        // Diagonals
        Symbol diag = lineWinner(0, 0, 1, 1);
        if (diag != Symbol.EMPTY) return diag;
        Symbol anti = lineWinner(0, size - 1, 1, -1);
        if (anti != Symbol.EMPTY) return anti;
        return Symbol.EMPTY;
    }

    private Symbol lineWinner(int startRow, int startCol, int dRow, int dCol) {
        Symbol first = grid[startRow][startCol];
        if (first == Symbol.EMPTY) return Symbol.EMPTY;
        int r = startRow, c = startCol;
        for (int i = 0; i < size; i++) {
            if (grid[r][c] != first) return Symbol.EMPTY;
            r += dRow;
            c += dCol;
        }
        return first;
    }

    public Board copy() {
        Board clone = new Board(size);
        for (int r = 0; r < size; r++) {
            System.arraycopy(grid[r], 0, clone.grid[r], 0, size);
        }
        return clone;
    }

    public void display() {
        for (int r = 0; r < size; r++) {
            StringBuilder sb = new StringBuilder("  ");
            for (int c = 0; c < size; c++) {
                sb.append(grid[r][c]);
                if (c < size - 1) sb.append(" ");
            }
            System.out.println(sb);
        }
    }
}
