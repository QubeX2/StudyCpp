#include <iostream>
#include <vector>
#include "format.hpp"

using namespace std::literals::string_literals;

namespace HR {
    class Person
    {
    public:
        Person(std::string name) : m_name(name) {};
        virtual ~Person() = default;

        virtual std::string toString()
        {
            return std::format("Person: {}\n", m_name);
        }

        std::string getName() { return m_name; }

    protected:
        std::string m_name;
    };

    class Employee : public Person
    {
    public:
        Employee(std::string name, int employeeId) : Person(name), m_employeeId(employeeId) {};
        virtual ~Employee() = default;

        virtual std::string toString()
        {
            return std::format("Employee: {}, ID: {}\n", m_name, m_employeeId);
        }

    protected:
        int m_employeeId;
    };

    class Manager : public Employee 
    {
    public:
        Manager(std::string name, int employeeId) : Employee(name, employeeId) {};
        Manager(const Employee& employee) : Employee(employee) {};
        std::string toString() override
        {
            return std::format("Manager: {}, ID: {}\n", m_name, m_employeeId);
        }
    };

    class Director : public Employee
    {
        public:
        Director(std::string name, int employeeId) : Employee(name, employeeId) {};
        Director(const Employee& employee) : Employee(employee) {};
        std::string toString() override
        {
            return std::format("Director: {}, ID: {}\n", m_name, m_employeeId);
        }
    };


};

int main()
{
    // CONSIDER!!
    // std::vector<HR::Person> persons;
    //
    // Will not work to store derived classes 
    // because persons have only room for a HR::Person.
    // Derived object variables will be sliced off.

    std::vector<std::unique_ptr<HR::Person>> persons;

    persons.emplace_back( std::make_unique<HR::Person>("Mikael Andersson") );
    persons.emplace_back( std::make_unique<HR::Director>( "Monika Qwisen", 10 ) );
    persons.emplace_back( std::make_unique<HR::Manager>("Clark Olofsson", 1110 ) );
    persons.emplace_back( std::make_unique<HR::Employee>( "Douglas Qwisen", 120 ) );
    persons.emplace_back( std::make_unique<HR::Employee>( "Lars-Erik Olsson", 2120 ) );
    persons.emplace_back( std::make_unique<HR::Employee>( "Göran Persson", 3310 ) );
    persons.emplace_back( std::make_unique<HR::Person>( "Ulla Brant" ) );
    persons.emplace_back( std::make_unique<HR::Director>( "Oskar Hedén", 410 ) );
        

    for(auto& person : persons) {
        std::cout << person->toString();
    }

    // Compiler made copy constructor
    HR::Employee em { "Douglas Lyckholm", 101 };
    HR::Manager mng { em };

    std::cout << mng.toString();

}