#include <iostream>
#include "format.hpp"

// A common guideline is that a destructor for a base class 
// must be either public and virtual or protected and nonvirtual

class Base 
{
public:
    virtual ~Base() = default;
    int getPublicNumber() const { return getNumber(); };

private:
    virtual int getNumber() const { return 10; };
};

// Java and C# doesn't allow overriding of a private method
// 
// Overriding a private and protected method is a good way
// to change a class without a major overhaul
class Derived : public Base
{
private:
    int getNumber() const override { return 20; };
};

int main()
{
    Base b;
    std::cout << std::format("{}\n", b.getPublicNumber());
    // prints 10

    Derived d;
    std::cout << std::format("{}\n", d.getPublicNumber());
    // prints 20
}