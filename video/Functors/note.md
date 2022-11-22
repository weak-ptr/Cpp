#  Functors
- background
  - in c++, the designer of **algorithm** want to use algorithm more flexible. so there are two kinds of version of same algorithm, one for default behavior, another for special behavior which can be explicit by user.

  - in c++, basic is compatibility with c language. but c++ also need compatibility with OOP. how to resolve the two questions, so the designer create a conception called **Functors**. which can compatibility between function pointer and OOP by using **template**.

## category
- Arithmetic
  ```c++
  template <class T>
  struct plus : public binary_function<T, T, T> {
    T operator()(const T& x, const T& y) const
    {
        return x + y;
    }
  };

  template <class T>
  struct minus : public binary_function<T, T, T> {
    T operator()(const T& x, const T& y) const
    {
        return x - y;
    }
  };

  //...
  ```

- Logicial
  ```c++
  template <class T>
  struct logical_and : public binary_function<T, T, bool> {
    bool operator()(const T& x, const T& y)
    {
        return x && y;
    }
  };
  //...
  ```

- Relational
  ```c++
  struct equal_to : public binary_function<T, T, bool> {
    bool operator()(const T& x, const T& y)
    {
        return x == y;
    }
  };

  struct less : public binary_function<T, T, bool> {
    bool operator()(const T& x, const T& y)
    {
        return x < y;
    }
  };
  //...
  ```

- summary
  - if you want using this functor correctly, you must read the source code and make sure you customer class has already defined those operator(must).

## self define functor integer into the system
- unary_function
  ```c++
  template <class Arg, class Result>
  struct unary_function {
    typedef Arg argument_type;
    typedef Result result_type;
  };
  ```

- binary_function
  ```c++
  template <class Arg1, class Arg2, class Result>
  struct binary_function {
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
  };
  ```

- according to STL, if you want you functor be adaptable, you must inherit **unary_function or binary_function**. because in some case, the **algorithm** maybe want know the functors type information.