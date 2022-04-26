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

    std::cout << std::format("PII: {}\n", pii) << std::endl;

    std::cout << std::format("infinity: {}\n", std::numeric_limits<double>::infinity);
}
