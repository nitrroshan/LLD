#pragma once
#include <string>
#include <memory>
#include <iostream>
#include "Image.h"
#include "RealImage.h"

// Virtual Proxy — same interface as RealImage, defers the expensive load
// until display() is first called (lazy loading).
class ProxyImage : public Image {
    std::string filename_;
    std::unique_ptr<RealImage> real_image_;   // not created until first use

public:
    explicit ProxyImage(std::string filename) : filename_(std::move(filename)) {
        std::cout << "  [ProxyImage] Created for " << filename_
                  << " (nothing loaded yet)\n";
    }

    void display() override {
        if (!real_image_) {
            real_image_ = std::make_unique<RealImage>(filename_);   // create on first display
        }
        real_image_->display();
    }
};
