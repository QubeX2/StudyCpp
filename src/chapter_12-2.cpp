#include <iostream>
#include <optional>
#include <random>
#include "format.hpp"

using namespace std::literals::string_literals;
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1, 6);
auto r = std::bind(distribution, generator);

std::optional<std::string> getNameOrNothing()
{
    int num = r();
    std::cout << std::format("Random: {} ==> ", num);
    if(num >= 4) {
        return "Is >= 4"s;
    }
    return std::nullopt;
}

int main()
{
    std::vector<int> v(10);

    int n = 0;
    std::generate(v.begin(), v.end(), [&n] { return n++; });

    for(auto i : v) {
        std::cout << i << ". ";
        auto name = getNameOrNothing();
        std::cout << (name ? name.value() : "Less than 4"s) << std::endl;
    }

}