#include <iostream>
#include <iterator>
#include <type_traits>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <typeinfo>

/*  display the category of common container  */
void _DisplayCategory(const std::output_iterator_tag)
{
    std::cout << "output_iterator_tag\n";
}

void _DisplayCategory(const std::input_iterator_tag)
{
    std::cout << "input_iterator_tag\n";
}

void _DisplayCategory(const std::forward_iterator_tag)
{
    std::cout << "forward_iterator_tag\n";
}

void _DisplayCategory(const std::bidirectional_iterator_tag)
{
    std::cout << "bidirectional_iterator_tag\n";
}

void _DisplayCategory(const std::random_access_iterator_tag)
{
    std::cout << "random_access_iterator_tag\n";
}

template <typename Iter>
void DisplayCategory(Iter iter)
{
    typedef typename std::iterator_traits<Iter>::iterator_category category;
    _DisplayCategory(category());
}

int main()
{
    std::cout << typeid(std::vector<int>()).name() << std::endl;
    std::cout << typeid(std::vector<std::string>()).name() << std::endl;

    std::cout << "std::array<int, 10>::iterator category = ";
    DisplayCategory(std::array<int, 10>::iterator());

    std::cout << "std::vector<int>::iterator category = ";
    DisplayCategory(std::vector<int>::iterator());

    std::cout << "std::list<int>::iterator category = ";
    DisplayCategory(std::list<int>::iterator());

    std::cout << "std::forward_listt<int>::iterator category = ";
    DisplayCategory(std::forward_list<int>::iterator());

    std::cout << "std::deque<int>::iterator category = ";
    DisplayCategory(std::deque<int>::iterator());

    std::cout << "std::map<int, string>::iterator category = ";
    DisplayCategory(std::map<int, std::string>::iterator());

    std::cout << "std::set<int>::iterator category = ";
    DisplayCategory(std::set<int>::iterator());

    std::cout << "std::unorder_map<int, string>::iterator category = ";
    DisplayCategory(std::unordered_map<int, std::string>::iterator());

    std::cout << "std::unorder_set<int>::iterator category = ";
    DisplayCategory(std::unordered_set<int>::iterator());

    std::cout << "std::istream = ";
    DisplayCategory(std::istream_iterator<int>());

    std::cout << "std::ostream = ";
    DisplayCategory(std::ostream_iterator<int>{std::cout, " "});

    return 0;
}