#include <iostream>
#include <algorithm>
#include <vector>

//  associative container
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define LOOP_TIMES  (100000)

template <typename T>
void MyRandomInsert(T& obj)
{
    obj = rand();
}

int main()
{
    vector<int> v1 (LOOP_TIMES);
    cout << v1.capacity() << endl;

    srand(0);
    for_each(v1.begin(), v1.end(), MyRandomInsert<int>);
    v1[LOOP_TIMES - 1] = 9527;

    vector<int>::iterator aim;
    aim = find(v1.begin(), v1.end(), 9527);
    if (aim != v1.end())
        cout << "find: " << *aim << endl;
    else
        cout << "no find" << endl;

    set<int> s1;
    for (int i = 0; i < LOOP_TIMES; ++i)
        s1.insert(rand());
    s1.insert(9527);

    auto iter = s1.find(9527);
    if (iter != s1.end())
        cout << "find: " << *iter << endl;
    else
        cout << "no find" << endl;

    return 0;
}