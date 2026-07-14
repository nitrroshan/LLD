#pragma once
#include "FileSystemNode.h"
#include <iostream>
#include <vector>
#include <memory>

// Composite — a directory that contains files and/or other directories
class Directory : public FileSystemNode {
private:
    std::string name_;
    std::vector<std::unique_ptr<FileSystemNode>> children_;

public:
    Directory(const std::string& name) : name_(name) {}

    void add(std::unique_ptr<FileSystemNode> node) {
        children_.push_back(std::move(node));
    }

    const std::vector<std::unique_ptr<FileSystemNode>>& get_children() const {
        return children_;
    }

    std::string get_name() const override { return name_; }

    int get_size() const override {
        int total = 0;
        for (const auto& child : children_) {
            total += child->get_size();
        }
        return total;
    }

    void print(const std::string& indent) const override {
        std::cout << indent << "D " << name_ << "/ (" << get_size() << " bytes)\n";
        for (const auto& child : children_) {
            child->print(indent + "  ");
        }
    }
};
