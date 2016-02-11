#include <iostream>
#include <type_traits>
using std::cout;
using std::endl;
using std::ostream;
extern void* enabler;

struct has_print_impl
{
    template < typename T >
    static auto check(T&& x) -> decltype( x.print(), std::true_type{} ) ;
    template < typenamAe T >
    static std::false_type check(...) ;
} ;
template <class T>
class has_print : public decltype(has_print_impl::check<T>(std::declval<T>())) {};

template < typename T >
auto print( T&& x )->decltype(x.print())
{
    return x.print();
}

template < typename T, std::enable_if_t<!has_print<T>::value>*& = enabler >
auto print( T&& x )->decltype(cout << x)
{
    return cout << x << endl;
}

void print(...){}

struct hoge_t { void print() { cout << "hogehoge" << endl;  } };
struct fuga_t {};
struct Foo{int v;};

ostream& operator << (ostream& s, Foo const& x){
    return s << x.v ;
}

int main()
{
    print( hoge_t{} );
    print( 12 );
    print(Foo{1});
    print( fuga_t{} );
}