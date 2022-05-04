#include <iostream>
#include "format.hpp"

class Bar
{
};

class Foo
{
public:
    Foo() : m_var(10) {};
    // disallow copy constructor
    Foo(const Foo& src) = delete;
    Foo& operator=(const Foo& rhs);

private:
    friend class Bar;
    //friend int Bar::processFoo(const Foo&);
    friend void printFoo(const Foo&);
    int m_var;
};

Foo& Foo::operator=(const Foo& rhs)
{
    // important! check for self assignment
    if(this == &rhs) {
        return *this;
    }

    m_var = rhs.m_var;
    return *this;
}

void printFoo(const Foo& f)
{
    std::cout << f.m_var << std::endl;
}

// lvalue reference
void handleMessage(std::string& message)
{
    std::cout << std::format("lvalue reference: {}\n", message);
} 

// rvalue reference
void handleMessage(std::string&& message)
{
    std::cout << std::format("rvalue reference: {}\n", message);
}

int main()
{
    // use friends only when needed
    Foo f;
    printFoo(f);

    //Foo f2 {f}; - not allowed
    Foo f3;
    f3 = f;

    printFoo(f3);

    std::string a { "Hello "};
    std::string b { "World" };
    handleMessage(a);
    // an expression, creates a temporary rvalue
    handleMessage(a + b);
    // std::move casts the lvalue to an rvalue reference
    handleMessage(std::move(b));
    
}