#include <iostream>
#include <limits>
#include "format.hpp"


int main() {
    std::cout << std::format("Hi i had {} times", 219) << std::endl;

    std::cout << std::format("Max int: {}\n", std::numeric_limits<int>::max());
    std::cout << std::format("Min int: {}\n", std::numeric_limits<int>::min());
    std::cout << std::format("Max long long: {}\n", std::numeric_limits<long long>::max());

    float pi = 3.14f;

    int pii = static_cast<int>(pi);

    std::cout << std::format("PII: {}\n", pii);

    std::cout << std::format("infinity: {}\n", std::numeric_limits<double>::infinity);

    std::array arr {1, 2, 3, 4, 5, 6, 7 ,8};
    std::cout << std::format("array length: {}\n", arr.size());

    std::array arr2 {10, 11, 12};

    auto [x, y, z] { arr2 };

    std::cout << std::format("x: {}, y: {}, z: {}\n", x, y, z);

    for(std::array an {1, 2, 3, 4, 5, 6, 7, 8}; auto a : an) {
        std::cout << std::format("number: {}\n", a);
    }

}
