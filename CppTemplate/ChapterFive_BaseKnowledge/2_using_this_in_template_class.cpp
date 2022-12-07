#include <iostream>
using namespace std;

void show(void)
{
    cout << "call global::show() function" << endl;
}

template <typename T>
class Base {
public:
    void show()
    {
        cout << "call Base::exit() function" << endl;
    }
};

template <typename T>
class Derived : public Base<T> {
public:
    void foo()
    {
        //show();
        //this->show();
        Base<T>::show();
    }
};

#include <string>
#include <deque>
#include <vector>
#include <exception>

namespace TheTemplateArgumentOfTemplate
{
    class EmptyStack : public std::exception {
    private:
        std::string m_err_msg;

    public:
        explicit EmptyStack(const std::string& err_msg)
            : std::exception(), m_err_msg(err_msg)
        {

        }

        virtual const char* what()
        {
            return m_err_msg.c_str();
        }
    };

    template <typename T, template<typename ValueType, typename ALLOC = std::allocator<ValueType>> class Container = std::deque>
    class Stack {
    private:
        Container<T> m_container;

    public:
        void push(const T& elem);

        void pop();

        T top() const;

        bool empty() const;

        template <typename T2, template<ValueType2 = T2, typename = std::allocator<ValueType>> class OtherContainer>
        Stack<T, Container>& operaotr=(const Stack<T2, OtherContainer>&);
    };

    template <typename T, template <typename, typename> class Container>
    void Stack<T, Container>::push(const T& elem)
    {
        m_container.push_back(elem);
    }

    template <typename T, template <typename, typename> class Container>
    void Stack<T, Container>::pop()
    {
        if (m_container.empty())
            throw EmptyStack("Stack<>::pop(): empty stack");

        m_container.pop_back();
    }

    template <typename T, template <typename, typename> class Container>
    T Stack<T, Container>::top() const
    {
        if (m_container.empty())
            throw EmptyStack("Stack<>::top(): empty stack");

        return m_container.back();
    }

    template <typename T, template <typename, typename> class Container>
    bool Stack<T, Container>::empty() const
    {
        return m_container.empty();
    }

    template <typename T, template<typename, typename> class Container>
        template <typename T2, template<ValueType2 = T2, typename = std::allocator<ValueType>> class OtherContainer>
    Stack<T, Container>& Stack<T, Container>::operator=(const Stack<T2, OtherContainer>& op2)
    {
        if (this == &op2)
            return *this;

        Stack<T2, OtherContainer> tmp(op2);
        m_container.clear();

        while(!tmp.empty())
        {
            m_container.push_front(tmp.top());
            tmp.pop();
        }

        return *this;
    }
}

int main()
{
    TheTemplateArgumentOfTemplate::Stack<int, vector> s1;
    if (s1.empty())
        cout << "empty" << endl;
    else
        cout << "not empty" << endl;
    
    s1.push(10);
    cout << s1.top() << endl;

    return 0;
}