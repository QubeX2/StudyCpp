#include <iostream>
#include "format.hpp"

class Base
{
public:
    virtual ~Base() = default;

    virtual void overload() { std::cout << "Base overload()\n"; }
    virtual void overload(int i) { std::cout << std::format("Base overload(int {})\n", i); }
};

class Derived : public Base
{
public:
    void overload() override { std::cout << "Derived overload()\n"; }
};

class Derived2 : public Base
{
public:
    using Base::overload;
    void overload() override { std::cout << "Derived overload()\n"; }
};

int main()
{
    Derived d1;
    d1.overload();
    //d1.overload(2); this will not compile not explicitly overridden

    Derived2 d2;
    d2.overload(13); // this work now because of using Base::overload

    // to avoid bugs always override all versions of an overloaded method
}