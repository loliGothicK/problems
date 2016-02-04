#include <iostream>
#include "class_header.hpp"
using namespace Interface;

int main ()
{
	Z z = Z();
	auto a = z.create<A>();//shared_ptr<A>が返り値
	auto calc = z.getInterface<E>();//E::calculateが返り値
	std::cout << a->calculate(1,1) << std::endl;//OK Aからの呼び出し
	std::cout << calc(1,2) << std::endl;//OK calcはEのcalculate
	return 0;
}