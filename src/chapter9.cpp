#include <iostream>
#include <utility>
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

class MoveClass
{
public:
    MoveClass(std::string s) : m_string(s) {}
    MoveClass(MoveClass&& src) noexcept : m_string(std::move(src.m_string)) 
    {
        std::cout << "Move Contructor\n";
    }
    MoveClass& operator=(MoveClass&& rhs) noexcept
    {
        m_string = std::move(rhs.m_string);
        std::cout << "Move assigned\n";
        return *this;
    }
    void print()
    {
        std::cout << std::format("String: {}\n", m_string);
    }
private:
    std::string m_string;
};

class MutEx
{
private:
    mutable int m_accessed {};
    int m_data { 1337 };
public:
    int getData() const 
    {   
        m_accessed++; // is changable because of "mutable"
        return m_data;
    }
};

class ConstClass
{
public:
    ConstClass(std::string s) : m_text(s) {}
    std::string& getText() 
    { 
        std::cout << "-- non const\n"; 
        return const_cast<std::string&>(std::as_const(*this).m_text); 
    }
    const std::string& getText() const 
    {
        std::cout << "-- const\n"; 
        return m_text; 
    }

private:
    std::string m_text { "Hello World! "};
};

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

    MoveClass mc1 { "Hello" };
    MoveClass mc2 { "World" };
    MoveClass mc3 { "" };
    mc3 = std::move(mc1);
    mc3.print();
    MoveClass mc4 = std::move(mc2);
    mc4.print();
    MoveClass mc5 { MoveClass("Big") };
    mc5.print();

    int xz = 22;
    int yz = 11;
    std::cout << std::format("before: {}, {}\n", xz, yz);
    xz = std::exchange(yz, 22);
    std::cout << std::format("after: {}, {}\n", xz, yz);   

    const ConstClass c1 { "Hello Const!" };
    ConstClass c2 { "Hello Non Const" };
    std::cout << c1.getText() << std::endl;
    std::cout << c2.getText() << std::endl;
}