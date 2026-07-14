#pragma once
#include <iostream>
#include "GameObserver.h"

// Observer — prints game events to the console.
class ConsoleGameObserver : public GameObserver {
public:
    void on_move(const Position& from, const Position& to, Piece* moved, Piece* captured) override {
        std::cout << "  " << (moved ? moved->glyph() : '?') << ' '
                  << from.to_string() << "->" << to.to_string();
        if (captured) std::cout << " captures " << captured->glyph();
        std::cout << "\n";
    }
    void on_check(Color in_check) override {
        std::cout << "  >> " << to_string(in_check) << " is in CHECK\n";
    }
    void on_checkmate(Color winner) override {
        std::cout << "  >> CHECKMATE — " << to_string(winner) << " wins!\n";
    }
    void on_stalemate() override {
        std::cout << "  >> STALEMATE — draw\n";
    }
};
