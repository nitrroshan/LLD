#include <iostream>
#include <memory>
#include "Image.h"
#include "ProxyImage.h"

int main() {
    std::cout << "=== Proxy Pattern Demo (Virtual / Lazy Loading, C++) ===\n\n";

    // Creating the proxies is cheap — no disk load happens here
    std::cout << "Creating image proxies (no loading expected):\n";
    std::unique_ptr<Image> photo1 = std::make_unique<ProxyImage>("vacation.jpg");
    std::unique_ptr<Image> photo2 = std::make_unique<ProxyImage>("portrait.jpg");

    // The heavy load happens only when display() is first called
    std::cout << "\nFirst display of photo1 (triggers load):\n";
    photo1->display();

    std::cout << "\nSecond display of photo1 (already loaded, no reload):\n";
    photo1->display();

    std::cout << "\nphoto2 was never displayed — so it was never loaded.\n";
    std::cout << "That is the point of a virtual proxy: pay the cost only if used.\n";

    return 0;
}
