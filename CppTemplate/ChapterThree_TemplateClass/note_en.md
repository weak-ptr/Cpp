[toc]

#  Template Class

##  How to declaration a Template Class?
- template keyword with template argument which enbrace by angle brackets.

- class keyword with class name.
  
- class member declaration and defination.
  - implicit inline
  - explicit inline
  
- demo
  ```c++
  template <typename T>
  class MyClass {
  private:
    //  data declaration
    T m_data;
  public:
    //  implicit inline definition by class name
    MyClass()
        : m_data()
    {

    }
    //  or implicit inline definition by type name
    MyClass<T>()
        : m_data()
    {

    }

    //  explicit definition by class name
    MyClass(MyClass<T>& obj);
    //  or explicit definition by type name
    MyClass<T>(MyClass<T>& obj);

    void other(void)
    {

    }
  };

  template <typename T>
  MyClass<T>::MyClass(MyClass<T>& obj)
  {

  }

  template <typename T>
  MyClass<T>::MyClass<T>(MyCLass<T>& obj)
  {

  }

  template <typename T>
  void MyClass<T>::other(void)
  {

  }
  ```

  - summary
    - for constructor and destructor function, class name equal to type name(gcc forbidden, msvc allowed).
    - for a template class, all of its member function are template function.
    - for a template class, the **type name** field is **must**.

##  What time the Member function of Template Class is compiled?
- the member function of template class only be check or be compiler when its be called.

- demo(see: textbook.cpp -> WhatTimeCompilingTemplate::CompilingTest)

##  How the class template specilization?
- must already defined a generalization conception.

- then, define a specilization conception.
  - for specilization one, you don't need template argument anymore.

  - for specilization one, you need **explicit** the type name.

- demo
  ```c++
  template <typename T>
  class Generalization {

  };

  template <>
  class SpecilizationIntTypeName<int> {

  };

  template <>
  class SpecilizationDoubleTypeName<double> {

  };
  ```

##  How the class template Partial_Specilization?
- What need partial specilization?
  - think about this situation, a class template need lots of argument, but some of i don't want use, another we need continue use anymore.

- How parital specilization?
  - first, the generalization conception need be defined first.

  - second, start defined the partial specilization conception.
    - define the the template argument which you need.
    - redefined the type name.

  - demo
  ```c++
  template <typename T1, typename T2, typename T3>
  class Generalization {

  };

  template <typename T>
  class Partial_Specilizaition_All_Same<T, T, T> {

  };

  template <typename T1, typename T2>
  class Partial_Specilization_Last_INT<T1, T2, int> {

  };
  ```

- the conflict between **Generalization** and **Partial Specilization** --- ambiguous
  - if you called match different parital specilization same time, the compiler will confuse, and raise error message.
  - example: int above code, if you call **Partial_Specialization\<int, int, int\>**, it match the template **Partial_Specilization_All_Same** and **Partial_Specialization_Last_INT**.

##  the priority of the specilizaiton(top to low)
- priority
  - specilization(top)
  - parital specilization(middle)
  - generalization(low)

- summary
  - if there are same priority candidates template, will cause ambiguous.

##  How to defination a class template with defualt argument?
- in some situation, like function. designer will support default argument to user. so the template also need have this option. 

- the behavior like function default argument.
  - only can support default argument for right to left.
  - because this template argument is optional, so we need support a sign also, then use assignment operator to the default type.

- demo
  ```c++
  template <typename T, typename Container = std::vector<T>>
  class MyClass {

  };
  ```

- attention
  - default template argument just a trick, it don't effect the priority of the template.