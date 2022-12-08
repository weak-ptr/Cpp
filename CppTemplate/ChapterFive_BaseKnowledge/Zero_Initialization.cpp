#include <iostream>
using namespace std;

template <typename T>
void ZeroInitCheck(void)
{
    T t1;
    T t2 = T();
    T t3 {};

    cout << t1 << endl;
    cout << t2 << endl;
    cout << t3 << endl;
}

template <typename T>
class MyClass {
private:
    T m_data;

public:
    /*  keyword of explicit  */

    MyClass()
        : m_data{}
    {

    }

    explicit MyClass()
        : m_data{}
    {

    }
};

int main()
{
    ZeroInitCheck<int>();

    return 0;
}