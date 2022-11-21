# Iterator
- What?
  - **Iterator** is a *object* which can point to some elements of **container**.

- Why?
  - in **C** language, the pointer is powerful and useful. but **C++** is OOP language, the original pointer conception is not suit the container of C++. so C++ extraction the pointer conception and abstraction to the **Iterator**.

- How?
  - different container need different iterator, Depending on the properties supported by iterators, they are classified into five different categories.
    - output_iterator_tag
    - input_iterator_tag
    - forward_iterator_tag : public input_iterator_tag
    - bidirectional_iterator_tag : public forward_iterator_tag
    - random_access_iterator_tag : public bidirection_iterator_tag

## why implementation iterator category as Object
- then we can use specialization template function to separate each of them. if we use *enumeration*, all the code will mix up.

## a useful debug tool -- typeid
- we know that all function will be rename by c++ compiler with function name and argument type. the c++ class type also rename by c++ compiler.
- typeid(object) -> type_message_object -> print type message.