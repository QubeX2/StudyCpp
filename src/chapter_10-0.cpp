#include <iostream>
#include "format.hpp"

class A 
{
public:
    virtual void go() { std::cout << "A go\n"; }
    void run() { std::cout << "A run\n"; }
};

class B : public A
{
public:
    void go() override { std::cout << "B go\n"; }
    void run() { std::cout << "B run\n"; }    
};


int main()
{
    A a;
    a.go();
    a.run();
    B b;
    b.go();
    b.run();

    B c;
    A& ref { c };

    ref.go();
    ref.run();

    A d { B {} };
    d.go();
}