#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <int Condition, typename T>
bool FindNumber(const T& candidate)
{
    return Condition == candidate;
}

struct FindClass {
private:
    const int m_confition;

public:
    FindClass(const int condition)
        : m_confition{condition}
    {

    }

    template <typename T>
    bool operator() (const T& obj)
    {
        return m_confition == obj;
    }
};

int main()
{
    FindClass F1 {3};
    vector<int> v1 { 1, 2, 2, 3, 3, 3 };
    
    cout << "count 1: " << count(v1.begin(), v1.end(), 1) << endl;

    cout << "count 2: " << count_if(v1.begin(), v1.end(), FindNumber<2, int>) << endl;

    cout << "count 3: " << count_if(v1.begin(), v1.end(), F1) << endl;

    return 0;
}
