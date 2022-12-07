[toc]

#  Tricky Basics
- Chapter detail:
  - Keyword **typename**
  - Zero initialization
  - Using **this->**(in template class)
  - Templates for **Raw Arrays(c-style?)** and **String Literals(c-style)**
  - Member Templates
  - Variable Templates
  - Template Template Parameters
  - Summary

##  Keyword typename
- official explanation:
  - The keyword **typename** was introduced during the standardization of the C++ to clarify that an **identifier** inside a template is a **type**.
  
- my opinion:
  - using typename keyword to tell the compiler, the icon which following the typename keyword is a type, then the c++ compiler will trust the programmer.

- demo:
  - normal
    ```c++
    template <typename T>   
    /*  first, tell the compiler in this template, all T icon is a type(so that, we can declaration a variable by using T icon in this scope)  */
    class MyClass {
    private:
        T m_variable_with_T_type;
    public:
        void foo()
        { 
            /*  (1): if T is a class which have public static member, following syntax can access it.  */
            T::Public_Static_Member_Data;// access variable

            /*  (2): if inside type T, there are other public type, we want use it  */
            typename T::PublicInsideClass component_variable; /*  definition variable  */
            typename T::PublicInsideClass component_ptr; /*  definition pointer variable  */

            /*  (3): if the subtype which in type T is used frequencily, we can do following to simply  */
            typedef typename T::PublicInsideClass OftenUse;

            OftenUse a, b, *c, &d = a;  //  ok
        }
    };
    ```
  
  - STL
    ```c++
    /*  in C++ STL, all the algorithm template using this skill to get the iterators message  */
    #include <iostream>

    //  print elements by iterator
    template <typename T>
    void printcoll(const T& coll)
    {
        typename T::const_iterator pos(coll.begin());
        typename T::const_iterator end(coll.end());

        for (; pos != end; ++pos)
            std::cout << *pos << ' ';
        std::cout << std::endl;
    }

    /*  obviously, above algorithm can't using with c-style array, so the algorithm do following modify  */
    //TODO: std::iterator_traits<T>::value_type
    ```

- summary
  - in template, using typename to explicit declaration that you are using type.

##  The Template Argument of Template
###  origin(history)
- as we know, all template need **type** to instance. so there are a situation(like STL::container), we also need instance a type first, then regard this type as template argument. the C++ program think this is unnecessary.
  - like following
  ```c++
  //    definition
  template <typename T, typename Container = std::vector<T>>
  class MyClass
  {

  };

  //    call
  int main()
  {
    /*  c++ programer think repeat int type is unnecessary  */
    MyClass<int, std::vector<int>> mc1; //  unnecessary

    //  aim
    MyClass<int, std::vector> mc2;      //  more comfortable

    return 0;
  }
  ```

###  grammer
- the solution --- regard other template as this template argument
  - as we all know, c and c++ is a static type languages. the compiler need know the type of you argument. so, we add **typename** keyword to tell compiler the following icon is a type. but template not a type, How we tell the compiler the following icon is a **template type**, you need instance it. --- the answer is **using Template keyword**.
  - like following
    ```c++
    template <typename T/*  T is a type  */, template <typename> class ICON/*  ICON is a template, can generator a type instance  */>
    class MyClass {

    };
    ```
  - keyword
    - need **explicit using template<> class** declaration.
    - an empty template parameter list is **not allowed in a template template parameter declaration**.(this is a restrict for template, you tell the compiler you will give a template, but if the template don't need argument, this is odd.)
    - ~~textbook say the **class** keyword can't be replace by **typename**~~(notine -- in g++ 11.3, the class can also be repeat by typename, compiler ok, the runing result ok)
    - template function don't support template argument of template. 

###  argument match in template argument of template
