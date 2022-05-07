#include <iostream>
#include "format.hpp"

class NestedClass
{
public:
    class InNest;
};

class NestedClass::InNest
{
public:
    InNest() = default;
    InNest(int x, int y) : m_x(x), m_y(y) {}
    std::pair<int, int> GetXY() { return std::pair<int, int>{m_x, m_y}; }
private:
    int m_x, m_y;
};

struct A
{
    A(){};
    int x, y;
};

struct B
{
    B() = default;
    int x, y;
};

int main()
{
    NestedClass::InNest ni{10, 11};
    auto [x, y] = ni.GetXY();
    std::cout << std::format("{}, {}\n", x, y);

    A a{};
    B b{};
    std::cout << std::format("A.x {}, A.y {} :: B.x {}, B.y {}\n", a.x, a.y, b.x, b.y);
}