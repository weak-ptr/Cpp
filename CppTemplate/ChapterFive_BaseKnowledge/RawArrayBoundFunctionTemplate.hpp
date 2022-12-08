#ifndef __CT_RAW_ARRAY_BOUND_HPP__
#define __CT_RAW_ARRAY_BOUND_HPP__

#include <iostream>
#include <string>

template <typename T, std::size_t SZ>
void func(T (&a)[SZ])
{
    std::cout << "bound\n";
}

template <typename T>
void func(T (&a)[])
{
    std::cout << "unbound\n";
}

template <typename T, std::size_t SZ>
void func(T [SZ])
{
    std::cout << "another bound\n";
}

int x[] = {1, 2, 3};

void TEST(void)
{
    int i[10];
    int j[] = {1, 2, 3};
    extern int x[];

    func(i);        //  bound
    func(j);        //  bound
    func(x);
}

#endif  /*  __CT_RAW_ARRAY_BOUND_HPP__  */