#include <iostream>
#include "format.hpp"

template<typename T>
class Grid
{
public:
    Grid(T x, T y) : m_x(x), m_y(y) {};
    virtual ~Grid() = default;
    
    template<typename>
    friend class Grid;

    // templated copy constructor and assignment operator
    // to allow: Grid<int> { Grid<double>{} };

    template<typename E>
    Grid(const Grid<E>& src)
    {
        m_x = src.m_x;
        m_y = src.m_y;
    }

    template<typename E>
    Grid& operator=(const Grid<E>& rhs)
    {
        m_x = rhs.m_x;
        m_y = rhs.m_y;
        return *this;
    }

    void print()
    {
        std::cout << std::format("{}, {}\n", m_x, m_y);
    }

private:
    T m_x {0};
    T m_y {0};
};

int main()
{
    Grid<int> gi { 2, 3 };
    Grid<double> gd1 { 7.2f, 3.1f };
    gd1.print();

    Grid<int> gi2 { gd1 };
    gi2.print();

    gd1 = gi;
    gd1.print();

    Grid<double> gd2 { gi };
    gd2.print();

    Grid<int> gi3 { Grid<float> {9.8f, 3.3f }};
    gi3.print();
}