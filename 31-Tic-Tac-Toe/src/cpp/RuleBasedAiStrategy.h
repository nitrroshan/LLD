#pragma once
#include <vector>
#include "MoveStrategy.h"
#include "Board.h"

// Concrete Strategy — heuristic AI: win, else block, else center, else corner,
// else first available. Look-ahead uses board copies (no side effects).
class RuleBasedAiStrategy : public MoveStrategy {
public:
    Move choose_move(const Board& board, Symbol symbol) override {
        Symbol opponent = (symbol == Symbol::X) ? Symbol::O : Symbol::X;
        std::vector<Move> moves = board.available_moves();

        // 1) Winning move
        for (const Move& move : moves) {
            Board copy = board.copy();
            copy.place_mark(move, symbol);
            if (copy.get_winner() == symbol) return move;
        }
        // 2) Block opponent's winning move
        for (const Move& move : moves) {
            Board copy = board.copy();
            copy.place_mark(move, opponent);
            if (copy.get_winner() == opponent) return move;
        }
        // 3) Center
        int mid = board.size() / 2;
        Move center{mid, mid};
        if (board.is_valid(center)) return center;
        // 4) Corners
        int last = board.size() - 1;
        Move corners[] = {{0, 0}, {0, last}, {last, 0}, {last, last}};
        for (const Move& corner : corners) {
            if (board.is_valid(corner)) return corner;
        }
        // 5) First available
        return moves.front();
    }
};
