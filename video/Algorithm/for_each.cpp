#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
void FormatDisplay(const T& obj)
{
    cout << ' ' << obj;
}

class FormatDisplayClass {
public:
    template <typename T>
    void operator() (const T& obj)
    {
        cout << "***" << obj;
    }
} object;

int main()
{
    vector<int> v1 { 10, 20, 30};
    for_each(v1.begin(), v1.end(), FormatDisplay<int>);     //      need specialization
    for_each(v1.begin(), v1.end(), object);                 //      don't need specialization

    return 0;
}