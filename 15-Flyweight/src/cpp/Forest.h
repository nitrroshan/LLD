#pragma once
#include <vector>
#include <string>
#include "Tree.h"
#include "TreeFactory.h"

// Client — plants many trees. Each Tree holds only its position;
// the heavy shared data lives once per TreeType in the factory.
class Forest {
    std::vector<Tree> trees_;
    TreeFactory factory_;

public:
    void plant_tree(int x, int y, const std::string& name,
                    const std::string& color, const std::string& texture) {
        auto type = factory_.get_tree_type(name, color, texture);
        trees_.emplace_back(x, y, type);
    }

    void draw() const {
        for (const auto& tree : trees_) {
            tree.draw();
        }
    }

    std::size_t tree_count() const { return trees_.size(); }
    std::size_t distinct_type_count() const { return factory_.distinct_type_count(); }
};
