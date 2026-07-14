#pragma once
#include <memory>
#include "Piece.h"
#include "MovementStrategies.h"
#include "Color.h"
#include "PieceType.h"

// Factory — builds a piece wired to its (shared, stateless) movement strategy.
class PieceFactory {
public:
    static std::unique_ptr<Piece> create(Color color, PieceType type) {
        const MovementStrategy* strategy = nullptr;
        switch (type) {
            case PieceType::King:   strategy = &KingMovementStrategy::instance(); break;
            case PieceType::Queen:  strategy = &QueenMovementStrategy::instance(); break;
            case PieceType::Rook:   strategy = &RookMovementStrategy::instance(); break;
            case PieceType::Bishop: strategy = &BishopMovementStrategy::instance(); break;
            case PieceType::Knight: strategy = &KnightMovementStrategy::instance(); break;
            case PieceType::Pawn:   strategy = &PawnMovementStrategy::instance(); break;
        }
        return std::make_unique<Piece>(color, type, strategy);
    }
};
