# algorithm
- STL algorithm interface format
  ```c++
  namespace std
  {
    template <typename Iterator, typename Initialize>
    Algorithm(Iterator first, Iterator last, Initialize init)
    {
        //  default behavior
    }

    template <typename Iterator, typename Initialize, typename BinaryOperator>
    Algorithm(Iterator first, Iterator last, Initialize init, BinaryOperator operator)
    {
        //  customer behavior
        init = Operator(init, *first);
    }
  }
  ```

- summary
  - iterator + behavior(have default but also can customer design) + initialize(depend the algorithm)

- notice
  - if you want algorithm do customer behavior, optional following need take care:
    - function is alway find.
    - function template will be raised error with message that **no instance of function name xxx or no matching function for call to xxx**, it means you need instance you template function.
    - class with template member function, maybe alway ok(not sure).
    - template class with template member function, maybe alway ok(not sure).