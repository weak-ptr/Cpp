#ifndef __CT_PASS_ARRAY_TO_CLASS_TEMPLATE_HPP__
#define __CT_PASS_ARRAY_TO_CLASS_TEMPLATE_HPP__

#include <iostream>
#include <string>

const std::string PassByValue {"Pass By Value"};
const std::string PassByReference {"Pass By Reference"};

template <typename T>
class MyClass;

template <typename T, std::size_t SZ>
class MyClass<T [SZ]> {
public:
    auto check()
    {
        return PassByValue;
    }
};

template <typename T, std::size_t SZ>
class MyClass<T (&)[SZ]> {
public:
    auto check()
    {
        return PassByReference;
    }
};

void TEST(void)
{
    int c1[10];
    auto& c2 = c1;

    MyClass<decltype(c1)> m1;
    std::cout << m1.check() << std::endl;   //  pass by value

    MyClass<decltype(c2)> m2;
    std::cout << m2.check() << std::endl;   //  pass by reference
}

#endif  /*  __CT_PASS_ARRAY_TO_CLASS_TEMPLATE_HPP__  */