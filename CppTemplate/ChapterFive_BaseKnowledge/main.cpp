


#define TEST_BOUND_FUNCTION
#if defined(TEST_FUNCTION)
    #include "PassRawArrayToFunctionTemplate.hpp"
#elif defined(TEST_CLASS)
    #include "PassRawArrayToClassTemplate.hpp"
#elif defined(TEST_BOUND_FUNCTION)
    #include "RawArrayBoundFunctionTemplate.hpp"
#else

void TEST()
{

}

#endif

int main()
{
    int i[10];
    auto& j = i;

    std::cout << typeid(int [10]).name() << std::endl;
    std::cout << typeid(int (&)[10]).name() << std::endl;
    std::cout << typeid(int []).name() << std::endl;
    std::cout << typeid(int (&)[]).name() << std::endl;
    std::cout << typeid(i).name() << std::endl;
    std::cout << typeid(j).name() << std::endl;
    std::cout << typeid(decltype(i)).name() << std::endl;
    std::cout << typeid(decltype(j)).name() << std::endl;

    TEST();

    return 0;
}