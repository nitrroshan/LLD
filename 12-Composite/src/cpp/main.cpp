#include <iostream>
#include <memory>
#include "File.h"
#include "Directory.h"

int main() {
    std::cout << "=== Composite Pattern Demo (C++) ===\n\n";

    auto root = std::make_unique<Directory>("project");
    root->add(std::make_unique<File>("README.md", 150));
    root->add(std::make_unique<File>(".gitignore", 30));

    auto src = std::make_unique<Directory>("src");
    src->add(std::make_unique<File>("Main.java", 500));
    src->add(std::make_unique<File>("Utils.java", 300));
    src->add(std::make_unique<File>("Config.java", 200));

    auto test = std::make_unique<Directory>("test");
    test->add(std::make_unique<File>("MainTest.java", 400));
    test->add(std::make_unique<File>("UtilsTest.java", 250));
    src->add(std::move(test));

    root->add(std::move(src));

    auto docs = std::make_unique<Directory>("docs");
    docs->add(std::make_unique<File>("guide.md", 800));
    docs->add(std::make_unique<File>("api.md", 600));
    root->add(std::move(docs));

    // 1. Print the entire tree
    std::cout << "--- File System Tree ---\n";
    root->print("");
    std::cout << "\n";

    // 2. Uniform treatment
    std::cout << "--- Sizes ---\n";
    std::cout << "root total: " << root->get_size() << " bytes\n";

    // 3. Iterate children
    std::cout << "\n--- Direct children of root ---\n";
    for (const auto& child : root->get_children()) {
        std::cout << "  " << child->get_name() << " -> " << child->get_size() << " bytes\n";
    }

    return 0;
}
