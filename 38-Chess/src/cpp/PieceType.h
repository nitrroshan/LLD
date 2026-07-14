#pragma once

// The six kinds of chess piece.
enum class PieceType { King, Queen, Rook, Bishop, Knight, Pawn };

inline char symbol(PieceType t) {
    switch (t) {
        case PieceType::King:   return 'K';
        case PieceType::Queen:  return 'Q';
        case PieceType::Rook:   return 'R';
        case PieceType::Bishop: return 'B';
        case PieceType::Knight: return 'N';
        case PieceType::Pawn:   return 'P';
    }
    return '?';
}
