#ifndef __CT_PASS_RAW_ARRAY_TO_FUNCTION_TEMPLATE_HPP__
#define __CT_PASS_RAW_ARRAY_TO_FUNCTION_TEMPLATE_HPP__

#include <iostream>
#include <string>
#include <typeinfo>

const std::string PassByValue {"Pass By Value"};
const std::string PassByReference {"Pass By Reference"};

template <typename T, std::size_t SZ>
auto func(T a[SZ])
{
    return PassByValue;
}

template <typename T, std::size_t SZ>
auto func(T (&a)[SZ])
{
    return PassByReference;
}

void TEST(void)
{
    int c1[10];
    auto& c2 = c1;

    std::cout << func(c1) << std::endl;     //  pass by reference
    std::cout << func(c2) << std::endl;     //  pass by reference

    /*  why explicit instantiation template alway mismatch argument???  */
    //std::cout << func<decltype(c1)>(c1) << std::endl;   //  compiler error: no matching function for call to 'func<int [10]>(int [10])'
    //std::cout << func<decltype(c2)>(c2) << std::endl;   //  compiler error: no matching function for call to 'func<int (&)[10]>(int [10])'
    //std::cout << func<decltype(c1)>(c2) << std::endl;   //  compiler error: no matching function for call to 'func<int [10]>(int [10])'
}

#endif  /*  __CT_PASS_RAW_ARRAY_TO_FUNCTION_TEMPLATE_HPP__  */