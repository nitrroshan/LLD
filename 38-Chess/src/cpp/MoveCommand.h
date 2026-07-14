#pragma once
#include <memory>
#include "Command.h"
#include "Board.h"
#include "Piece.h"
#include "Position.h"

// Command — a single move. execute() applies it and takes ownership of the
// captured piece (and the moved piece's prior hasMoved flag); undo() restores
// both. This is what makes king-safety simulation and undo/redo possible.
class MoveCommand : public Command {
    Board& board_;
    Position from_, to_;
    Piece* moved_ = nullptr;
    std::unique_ptr<Piece> captured_;
    bool prev_has_moved_ = false;

public:
    MoveCommand(Board& board, Position from, Position to)
        : board_(board), from_(from), to_(to) {}

    void execute() override {
        moved_ = board_.get_piece(from_);
        prev_has_moved_ = moved_->has_moved();
        captured_ = board_.move_piece(from_, to_);   // take ownership of captured
        moved_->set_moved(true);
    }

    void undo() override {
        board_.move_piece(to_, from_);               // move the piece back
        board_.set_piece(to_, std::move(captured_)); // restore captured (or nullptr)
        moved_->set_moved(prev_has_moved_);
    }

    Position from() const { return from_; }
    Position to() const { return to_; }
    Piece* captured_view() const { return captured_.get(); }   // valid after execute()
};
