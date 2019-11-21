#include <iostream>
#include <memory>
int main()
{

    auto derefLess = [](const auto &p1, const auto &p2) {
        return *p1 < *p2;
    };

    auto x = std::make_unique<int>(5);
    auto y = std::make_unique<int>(24);

    auto z1 = derefLess(x, y);
    auto z2 = derefLess(y, x);

    std::cout << "x<y:" << std::boolalpha << z1 << " y<x:" << z2 << std::endl;
}