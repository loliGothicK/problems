#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <type_traits>

namespace enum_hack {
    template <typename T>
    constexpr T PI = static_cast<T>(3.141592653589793238462643383279502884197L);

    template < typename T >
        inline constexpr std::remove_reference_t<T> sin(T&& arg) noexcept{
	    long double x = arg;
        bool sign = false;
	    if( x < 0) x = PI<long double> - x;
        while ( x > 2.L*PI<long double> ) x -= 2.L*PI<long double>;
        if( x > PI<long double> ) {
            x -= PI<long double>;
            sign = true;
        }
        auto w = 2.755731922398589E-6L*x*x;
        for(auto a : { -1.984126984126984E-4L, 8.33333333333333E-3L, -1.666666666666667E-1L, 1.L })
            w = w*x*x + a;
        return sign ? -w*x : w*x;
    }
}

int main(){
    constexpr auto x = enum_hack::sin(1.L);
    std::cout << std::fixed << std::setprecision(std::numeric_limits<decltype(x)>::digits10 + 1);
    std::cout << "enum_hack::sin(1)" << std::endl;
    std::cout << x << std::endl;
    std::cout << std::endl;
    std::cout << "std::sin(1)" << std::endl;
    std::cout << std::sin(1.L) << std::endl;

    long double th{};
    std::cout << std::endl;
    std::cout << "TEST" << std::endl;
    std::cout << "INPUT" << std::endl;
    std::cin >> th;
    std::cout << "enum_hack::sin(" << th << ") = " << enum_hack::sin(th) << std::endl;
    std::cout << "std::sin(" << th << ") = " << std::sin(th) << std::endl;
    return 0;
}
