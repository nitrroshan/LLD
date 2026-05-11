#pragma once
#include <string>
#include <sstream>

class House {
private:
    int rooms_;
    int floors_;
    bool has_garage_;
    bool has_pool_;
    bool has_garden_;
    std::string roof_type_;

    // Private constructor — only HouseBuilder can create a House
    friend class HouseBuilder;

    House(int rooms, int floors, bool has_garage, bool has_pool,
          bool has_garden, const std::string& roof_type)
        : rooms_(rooms), floors_(floors), has_garage_(has_garage),
          has_pool_(has_pool), has_garden_(has_garden), roof_type_(roof_type) {}

public:
    int rooms() const { return rooms_; }
    int floors() const { return floors_; }
    bool has_garage() const { return has_garage_; }
    bool has_pool() const { return has_pool_; }
    bool has_garden() const { return has_garden_; }
    const std::string& roof_type() const { return roof_type_; }

    std::string to_string() const {
        std::ostringstream oss;
        oss << "House [" << rooms_ << " rooms, "
            << floors_ << " floors, roof=" << roof_type_;
        if (has_garage_) oss << ", garage";
        if (has_pool_) oss << ", pool";
        if (has_garden_) oss << ", garden";
        oss << "]";
        return oss.str();
    }
};
