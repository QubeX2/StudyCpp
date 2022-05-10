#include <iostream>
#include <new>
#include "format.hpp"

template<typename T>
class TD;

void useRes(const std::weak_ptr<int> wptr)
{
    auto res { wptr.lock() };
    //TD<decltype(res)> tType; 
    if(res) {
        std::cout << "Resource still alive\n";
    } else {
        std::cout << "Resource has been freed\n";
    }
}

std::unique_ptr<int> createInt()
{
    auto ptr { std::make_unique<int>() };
    return ptr;
}

// memory management
//
int main()
{
    // never use auto_ptr

    // use only smart pointers RAII
    // the default pointer should be "unique_ptr"
    auto uptr { std::make_unique<int>(12) };
    std::cout << std::format("unique_ptr: {}\n", *uptr);

    // shared_ptr, always use "make_shared()" to create a shared ptr
    auto sptr { std::make_shared<double>(2.549f) };
    std::cout << std::format("shared_ptr: {:.2f}\n", *sptr);

    // weak_ptr reference to a shared_ptr use obj.lock() 
    auto sptr2 { std::make_shared<int>() };
    std::weak_ptr<int> wptr2 { sptr2 };
    useRes(wptr2);
    sptr2.reset();
    useRes(wptr2);

    // return smart pointers by value, (N)RVO "return value optimization"
    auto fptr { createInt() };


    // array of pointers delete each pointer individually    
    const size_t size { 4 };
    int** arr2 { new int*[size] };
    for(size_t i{}; i < size; i++) {
        arr2[i] = new int{static_cast<int>(i) + 1};
    }
    for(size_t i {}; i < size; i++) {
        std::cout << std::format("*arr2[i] = {}\n", *arr2[i]);
    }
    for(size_t i {}; i < size; i++) {
        delete arr2[i];
        arr2[i] = nullptr;
    }
    delete[] arr2;
    arr2 = nullptr;
    
    // in c++ use only new and delete they handle objects
    // pontier to an int    
    int* ptr { new int {17} };
    std::cout << *ptr << std::endl;
    delete ptr;
    ptr = nullptr;
    
    // pointer to a pointer to an int
    int** handle { nullptr };       // on stack
    handle = new int*;              // free store
    *handle = new int {42};         // free store
    std::cout << **handle << std::endl;
    delete *handle;
    delete handle;
    *handle = nullptr;
    handle = nullptr;
    
    // nothrow check for nullptr (do not use)
    int* ptr2 {new(std::nothrow) int {55} };
    if(ptr2 != nullptr) {
        std::cout << std::format("nothrow: {}\n", *ptr2);
    }
    delete ptr2;
    ptr2 = nullptr;
    
    // pointer to an array
    int* arr { new int[] { 1, 2, 3, 4, 5 }};
    std::cout << std::format("arr[2] = {}\n", arr[2]);
    delete[] arr;    
    arr = nullptr;

}