#include <functional>

namespace Interface{
    
    template < typename T >
    class callable {
    public:
        short operator()(short const& l, short const& r) { return T::Calculate(l,r); }
    };
    //interface of Addition
    class A : public callable<A>
    {
    public:
        //default ctor
        constexpr A() = default;
        ~A() = default;
        //calculate function object
        static short Calculate(short const& l, short const& r)
        {
            return l + r ;
        }
    } ;

    //interface of Subtraction
    class B : public callable<B>
    {
    public:
        constexpr B() = default;
        ~B() = default;

        static short Calculate(short const& l, short const& r)
        {
            return l - r ;
        }
    } ;

    //interface of Multiplication
    class C : public callable<C>
    {
    public:
        constexpr C() = default;
        ~C() = default;

        static short Calculate(short const& l, short const& r)
        {
            return l * r ;
        }
    } ;

    //interface of Division
    class D : public callable<D>
    {
    public:
        constexpr D() = default;
        ~D() = default;

        static short Calculate(short const& l, short const& r)
        {
            return l / r ;
        }
    } ;

    //interface of Special Operator
    class E : public callable<E>
    {
    public:
        constexpr E() = default;
        ~E() = default;

        static short Calculate(short const& l, short const& r)
        {
            return l + r + 5 ;
        }
    } ;


}
