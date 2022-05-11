#include <iostream>
#include <string_view>
#include "format.hpp"

class Base
{
public:
    virtual ~Base() = default;
    Base() = default;
    Base(std::string_view s) : m_string(s) {};
    std::string_view getString() { return m_string; };
private:
    std::string_view m_string;
};

class Derived : public Base
{
public:
    using Base::Base;
    Derived(int i) : m_int(i) {};
    Derived(std::string_view s, int i) : Base(s), m_int(i) {};

private:
    int m_int;
};

int main()
{
    Base b1 { "Hello Sven" };
    Derived d1 { 1 };
    Derived d2 { "Hello Mikael " };
    Derived d3;
    Derived d4 { "Hello Sune", 33 };

    std::cout << d2.getString() << std::endl;
    std::cout << d4.getString() << std::endl;
}