#include <iostream>
#include <limits>
#include <vector>
#include <array>
#include "format.hpp"


struct Person 
{
    std::string fistName;
    std::string lastName;
    int age;
    double length;
};

std::string getString1()
{
    return "this is string 1";
}

std::unique_ptr<std::string> getString2()
{
    return std::make_unique<std::string>("Mikael Andersson");
}

struct OddsAndEvens { std::vector<int> odds, evens; };

OddsAndEvens separateVector(std::vector<int>& vec) 
{
    std::vector<int> odds, evens;
    for(int i : vec) {
        if(i % 2 == 1) {
            odds.push_back(i);
        } else {
            evens.push_back(i);
        }
    }
    return OddsAndEvens { .odds = odds, .evens = evens };
}

std::string foo()
{
    return "Mikael Andersson";
}

int main() {
    // std::format
    std::cout << std::format("Hi i had {} times", 219) << std::endl;
    std::cout << std::format("Max int: {}\n", std::numeric_limits<int>::max());
    std::cout << std::format("Min int: {}\n", std::numeric_limits<int>::min());
    std::cout << std::format("Max long long: {}\n", std::numeric_limits<long long>::max());
    
    // static cast
    float pi = 3.14f;
    int pii = static_cast<int>(pi);
    std::cout << std::format("PII: {}\n", pii);
    
    // limits

#ifdef __linux__
    std::cout << std::format("infinity: {}\n", std::numeric_limits<double>::infinity);
#endif
    std::array arr {1, 2, 3, 4, 5, 6, 7 ,8};
    std::cout << std::format("array length: {}\n", arr.size());
    std::array arr2 {10, 11, 12};
    
    // structured bindings
    auto [x, y, z] { arr2 };
    std::cout << std::format("x: {}, y: {}, z: {}\n", x, y, z);
    
    // initialized loop
    for(std::array an {1, 2, 3, 4, 5, 6, 7, 8}; auto a : an) {
        std::cout << std::format("number: {}\n", a);
    }
    
    // designated initializers
    Person p {
        .fistName = "Mikael",
        .lastName = "Andersson",
        .age = 52
    };
    p.length  = 1.82;
    std::cout << std::format("Person: {}, {}, {}, {}\n", p.fistName, p.lastName, p.age, p.length);
    
    // pointer
    std::cout << getString1() << std::endl;
    std::cout << *getString2() << std::endl;
    
    // structured bindings
    std::pair myPair { "Mikael", 52 };
    const auto& [myName, myAge] = myPair;
    std::cout << std::format("const reference: {}, {}\n", myName, myAge);
    
    // prefer to return object - triggers return value optimizations
    std::vector<int> vec1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    OddsAndEvens oe = separateVector(vec1);
    std::cout << "Evens: ";
    for(int e : oe.evens) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    std:: cout << "Odds: ";
    for(int o : oe.odds) {
        std::cout << o << " ";
    }
    std::cout << std::endl;
    
    // decltype
    decltype(foo()) s { foo() };
    std::cout << s << std::endl;
    
}
