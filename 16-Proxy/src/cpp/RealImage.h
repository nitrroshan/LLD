#pragma once
#include <string>
#include <iostream>
#include "Image.h"

// RealSubject — the expensive object. The costly load happens in the constructor.
class RealImage : public Image {
    std::string filename_;

    void load_from_disk() {
        std::cout << "  [RealImage] Loading " << filename_ << " from disk (expensive)...\n";
    }

public:
    explicit RealImage(std::string filename) : filename_(std::move(filename)) {
        load_from_disk();
    }

    void display() override {
        std::cout << "  [RealImage] Displaying " << filename_ << "\n";
    }
};
