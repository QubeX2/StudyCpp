#include <iostream>
#include "format.hpp"

class Widget
{
public:
    Widget() = default;
    Widget(const std::string s) : m_string(s) {};
    Widget(const double d) : m_double(d) {};
    inline double getValue() const { return m_double; }
    inline std::string getString() const { return m_string; }
    friend Widget operator+(const Widget& lhs, const Widget& rhs)
    {
        return Widget { lhs.getValue() + rhs.getValue() };
    }
private:
    double m_double;
    std::string m_string;
};

int main()
{
    Widget w1 { 4 };
    Widget w2 = w1 + 4;
    Widget w3 = 4.5 + w2;


    std::cout << std::format("=> {}\n", w2.getValue());
    std::cout << std::format("=> {}\n", w3.getValue());
    

}
