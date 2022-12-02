#include <iostream>
#include <cstring>
#include <string>

//  
template <typename T>
inline const T& max(const T& a, const T& b)
{
    return a < b ? b : a;
}

//  
inline const char* max(const char* a, const char* b)
{
    return strcmp(a, b) < 0 ? b : a;
}

//
template <typename T>
inline const T& max(const T& a, const T& b, const T& c)
{
    return max(max(a,b), c);
}

int main()
{
    auto i = ::max(7, 42, 68);
    std::cout << i << std::endl;

    const char* s1 = "frederic";
    const char* s2 = "anica";
    const char* s3 = "lucas";

    auto j = ::max(s1, s2, s3);
    std::cout << j << std::endl;

    return 0;
}