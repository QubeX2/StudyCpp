#include <iostream>
#include "format.hpp"

class Bang
{
public:
    Bang(int bang) : m_bang(bang) {};

    [[nodiscard]] bool operator==(const Bang& rhs) const
    {
        return m_bang == rhs.m_bang;    
    }

    // nodiscar don't ignore return value
    [[nodiscard]] std::partial_ordering operator<=>(const Bang& rhs) const
    {
        return m_bang <=> rhs.m_bang;
    }
private:
    int m_bang;
};

int main()
{
    Bang b1{12};
    Bang b2{13};

    std::cout << std::format("b1 is bigger than b2 {}\n", b2 > b1);
    
    std::cout << std::format("12 == b1 ? {}\n", 12 == b1);
}
