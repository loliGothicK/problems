#include <memory>

namespace Interface{
	//Forward declaration for friend
	class Z ;

	//interface of Addition
	class A
	{
		//Z can only call A default ctor
		//All instances are make through Z factory
		friend Z ;
		A() = default;//default ctor
	public:	
		//noncopyable
		A(A const&) = delete ;//copy ctor
		A(A&&) = delete;// move ctor
		A operator=(A const&) = delete;//copy assignment
		A operator=(A&&) = delete;// move assinment
		//calculate function object
		std::function<short(short const&,short const&)> calculate = [](short const& l, short const& r)
		{
			return l+r ;
		} ;
	} ;

	//interface of Subtraction
	class B
	{
		friend Z ;
		B() = default;
	public:
		B(B const&) = delete;
		B(B&&) = delete;
		B operator=(B const&) = delete;
		B operator=(B&&) = delete;
		std::function<short(short const&,short const&)> calculate = [](short const& l, short const& r)
		{
			return l / r ;
		} ;
	} ;

	//interface of Multiplication
	class C
	{
		friend Z ;
		C() = default;
	public:
		C(C const&) = delete;
		C(C&&) = delete;
		C operator=(C const&) = delete;
		C operator=(C&&) = delete;
		std::function<short(short const&,short const&)> calculate = [](short const& l, short const& r)
		{
			return l * r ;
		} ;
	} ;

	//interface of Division
	class D
	{
		friend Z ;
		D() = default;
	public:
		D(D const&) = delete;
		D(D&&) = delete;
		D operator=(D const&) = delete;
		D operator=(D&&) = delete;
		std::function<short(short const&,short const&)> calculate = [](short const& l, short const& r)
		{
			return l / r ;
		} ;
	} ;

	//interface of Special Operator
	class E
	{
		friend Z ;
		E() = default;
	public:
		E(E const&) = delete;
		E(E&&) = delete;
		E operator=(E const&) = delete;
		E operator=(E&&) = delete;
		std::function<short(short const&,short const&)> calculate = [](short const& l, short const& r)
		{
			short tmp{} ;
			tmp+=l;tmp+=l;tmp+=r;tmp+=r;tmp+=5 ;
			return tmp ;
		} ;
	} ;

	//interface manager
	class Z
	{
	public:
		Z()	= default;
		~Z() = default;

		template< typename T >
		decltype(auto) create ()
		{
			return std::unique_ptr<T>{ new T() };
		}

		template< typename T >
		decltype(auto) getInterface ()
		{
			return T().calculate ;
		}
	} ;
}
