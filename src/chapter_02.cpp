#include <iostream>
#include "format.hpp"

using namespace std::literals::string_literals;

int main()
{
    // raw string literal
    const char* str { R"(Hi my name
"is" Mikael Andersson)" };
    std::cout << str << std::endl;
    
    // three way comparison
    std::string a { "12" };
    std::string b { "34" };

#ifdef __linux__
    auto result { a <=> b };
    if(is_lt(result)) { std::cout << "less\n"; }
    if(is_gt(result)) { std::cout << "greater\n"; }
    if(is_eq(result)) { std::cout << "equal\n"; }
#endif
    
    // string operations
    std::string str1 { "Hello!!" };
    std::string str2 { "The World..." };
    auto pos { str1.find("!!") };
    if(pos != std::string::npos) {
        str1.replace(pos, 2, str2.substr(3, 6));
    }
    std::cout << std::format(R"("{}")", str1) << std::endl;
    
    // string literals
    auto string1 { "Mikael Andersson"s };
    std::cout << string1 << std::endl;
    
    // numeric conversions
    std::string num { " 12334"s };
    size_t index {};
    int value { std::stoi(num, &index) };
    std::cout << std::format("numeric conversion: {}, index: {}\n", value, index);
    
    // format specifiers
    int i = {42};
    std::cout << std::format("|{:7}|\n", i);
    std::cout << std::format("|{:<7}|\n", i);
    std::cout << std::format("|{:_>7}|\n", i);
    std::cout << std::format("|{:_^7}|\n", i);
    
}