#include <iostream>
#include <string>
#include "format.hpp"

template <typename T>
struct DeducedType;

template <typename Key, typename Value>
class KeyValuePair
{
public:
    KeyValuePair(Key k, Value v) : m_key(k), m_value(v) {
        // DeducedType<Key>::value;
        // DeducedType<Value>::value;
    }
    virtual ~KeyValuePair() = default;

    Key& getKey() {
        return m_key;
    }
    Value& getValue() {
        return m_value;
    }
    void print() {
        //DeducedType<Value>::value;
        std::cout << std::format("Key: {}, Value: {}\n", m_key, m_value);
    }
private:
    Key m_key;
    Value m_value;
};

KeyValuePair(const char*, const char*) -> KeyValuePair<std::string, std::string>;
template <typename Key>
KeyValuePair(Key , const char*) -> KeyValuePair<Key, std::string>;
template <typename Value>
KeyValuePair(const char*, Value) -> KeyValuePair<std::string, Value>;


int main()
{
    KeyValuePair kvp1 { 2, "s" };
    kvp1.print();


}