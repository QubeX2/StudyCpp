#include <iostream>


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

int main()
{
    // use friends only when needed
    Foo f;
    printFoo(f);

    //Foo f2 {f}; - not allowed
    Foo f3;
    f3 = f;

    printFoo(f3);

}