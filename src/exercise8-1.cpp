#include <iostream>
#include "format.hpp"

using namespace std::literals::string_literals;

class Person
{
public:
    Person() : m_firstName(""s), m_lastName(""s) 
    {
        std::cout << "Default constructor called\n";
    }
    Person(const std::string first, const std::string last) : m_firstName(first), m_lastName(last) 
    {
        std::cout << "Constructor with initialization called\n";
    }
    // Person(const Person& src) : m_firstName(src.m_firstName), m_lastName(src.m_lastName)
    // {
    //     std::cout << "Copy constructor called\n";
    // }
    // ~Person() 
    // { 
    //     std::cout << "Destructor called\n"; 
    // }

    // Person& operator=(const Person& rhs)
    // {
    //     std::cout << "Assignment operator called\n"; 
    //     if(this == &rhs) {
    //         return *this;
    //     }
    //     m_firstName = rhs.m_firstName;
    //     m_lastName = rhs.m_lastName;
    //     return *this;
    // }

    void setName(const std::string first, const std::string last) 
    {
        m_firstName = first;
        m_lastName = last;
    }
    std::string getName() { return std::format("{} {}", m_firstName, m_lastName); }

private:
    std::string m_firstName;
    std::string m_lastName;
};

int main()
{
    Person p { "Mikael"s, "Andersson"s };  
    std::cout << p.getName() << std::endl;

    Person book[3] {
        { "Johan"s, "Göransson"s },
        { "Olle"s, "Jansson"s },
    };
    book[2].setName( "Urban"s, "Ringhelm"s );
    for(size_t i {}; i < std::size(book); i++) {
        std::cout << book[i].getName() << std::endl;
    }

    std::cout << "--- new features ---\n";
    Person p2 { p };
    std::cout << p2.getName() << std::endl;
    Person p3;
    p3 = p2;
    std::cout << p3.getName() << std::endl;

}