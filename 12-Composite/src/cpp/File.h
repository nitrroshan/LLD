#pragma once
#include "FileSystemNode.h"
#include <iostream>

// Leaf — a file with a fixed size
class File : public FileSystemNode {
private:
    std::string name_;
    int size_;

public:
    File(const std::string& name, int size) : name_(name), size_(size) {}

    std::string get_name() const override { return name_; }
    int get_size() const override { return size_; }

    void print(const std::string& indent) const override {
        std::cout << indent << "F " << name_ << " (" << size_ << " bytes)\n";
    }
};
