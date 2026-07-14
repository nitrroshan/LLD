#pragma once
#include <string>

// Component interface
class FileSystemNode {
public:
    virtual ~FileSystemNode() = default;
    virtual std::string get_name() const = 0;
    virtual int get_size() const = 0;
    virtual void print(const std::string& indent) const = 0;
};
