# Adapter
- background
  - in some situation, we have a better one container or functor. but for some purpose, we don't need all peculiarity. and we don't want to rebuild a new data structure. so we adapter it.

- What?
  - adapter is a **intermediary agent**.

- How?
  - STL alway use contain as a component.

## aim
- limit the interface
- rename the interface

## achieve
- inherit
- contain(STL)
- rename(recall)

## category
- Container Adapters
  - stack
  - queue
  
- Iterator Adapters
- Functor Adapters
  - bind2nd
    ```c++
    template <class Operation>
    class binder2nd : public unary_function<typename Operation::first_argument_type, typename Operation::result_type> {
    protected:
        Operation op;
        typename Operation::second_argument_type value;

    public:
        //  constructor
        binder2nd(const Operation& x, const typename Operation::second_argument_type& y)    //  second argument type limit
            : op(x), value(y)
        {

        }

        typename Operation::result_type 
        operation()(const typename Operation::first_argument_type& x) const                 //  first argument type limit and return value type limit
        {
            op(x, value);
        }
    };

    template <class Operation, class T>
    inline binder2nd<Operation>
    bind2nd(const Operation& op, const T& x)
    {
        //  ask compiler do type check
        typedef typename Operation::second_argument_type arg2_type;     //  asking for the type of operation::second_argument_type
        return binder2nd<Operation>(op, arg2_type(x));                  //  arg2_type() ---> type check(if type not match, compiler will raise ERROR)
    }

    //  call
    template <class InputIterator, class Predicate>
    typename iterator_traits<InputIterator>::difference_type
    count_if(InputIterator first, InputIterator last, Predicate pred)
    {
        typename iterator_trais<InputIterator>::difference_type n = 0;
        for (; first != last; ++first)
            if (pred(*first))
                ++n;
        
        return n;
    }

    //  std::less
    template<typename _Tp>
    struct less : public binary_function<_Tp, _Tp, bool>
    {
        bool
        operator()(const _Tp& __x, const _Tp& __y) const
        {
            return __x < __y;
        }
    };

    //  example
    cout << count_if(v1.begin(), v1.end(), bind2nd(less<int>(), 40));

    //  step one: 
    less<int>() --> __@temp_less_obj
    //  step two:
    bind2nd(__@temp_less_obj, 40) --> binder2nd<less<int>>(__@temp_less_obj, int(40))
    //  step three:
    parent: 
        unary_function<less<int>::first_argument_type, less<int>::result_type>  //  all typedef
    //  step four:
    child: 
        op(__@temp_less_obj), value(int(40)) --> return __@temp_op_obj
    //  step five:
    in count_if:
        pred(*first) --> __@temp_op_obj(*first) --> binder2nd()(&__@temp_op_obj, *first) --> (&__@temp_op_obj)->op(*first) --> (&__@temp_op_obj)->__@temp_less_obj(*first)
    ```