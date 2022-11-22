#include <iostream>
#include <functional>
#include <numeric>
#include <vector>
using namespace std;

int AccumulateTestFunction(int i, int j)
{
    return i + 2 * j;
}

class AccumulateTestClass {
public:
    int operator ()(int i, int j)
    {
        return i + 3 * j;
    }
} obj;

int main()
{
    int init = 100;
    int a[] { 10, 20, 30};
    vector<int> v { 10, 20, 30};

    /*  default operator */
    cout << "accumulate a[]: " << accumulate(a, a + 3, init) << endl;
    cout << "accumulate vector: " << accumulate(v.begin(), v.end(), init) << endl;

    /*  call my function  */
    cout << "accumulate with AccumulateTestFunction: " << accumulate(a, a + 3, init, AccumulateTestFunction) << endl;
    cout << "accumulate vector: " << accumulate(v.begin(), v.end(), init, AccumulateTestFunction) << endl;

    /*  call my functional  */
    cout << "accumulate with obj: " << accumulate(a, a + 3, init, obj) << endl;
    cout << "accumulate with obj: " << accumulate(v.begin(), v.end(), init, obj) << endl;

    return 0;
}