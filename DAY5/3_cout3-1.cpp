// 6_cout - 187page
//#include <iostream>
#include <cstdio>

namespace std
{
	class ostream
	{
	public:
		ostream& operator<<(int n) { printf("%d", n); return *this; }
		ostream& operator<<(double d) { printf("%lf", d); return *this; }
		ostream& operator<<(const char* s) { printf("%s", s); return *this; }

		ostream& operator<<(ostream& (*f)(ostream&))
		{
			return f(*this); 
		}
	};
	ostream cout;

	ostream& endl(ostream& os)
	{
		os << "\n";
		return os;
	}
}
std::ostream& tab(std::ostream& os)
{
	os << "\t";
	return os;
}
std::ostream& menu(std::ostream& os)
{
	os << "1. 김밥\n";
	os << "2. 라면\n";
	return os;
}
int main()
{
	std::cout << "A" << std::endl; // ok..

	// 표준에 "std::endl"은 있지만 "tab"은 없습니다.

	std::cout << "B" << tab << "C" << std::endl; // tab을 생각해 봅시다.
	
//	std::cout << tab;	// cout.operator<<(tab)
						// cout.operator<<(ostream&(*)(ostream&)) 즉, 함수포인터버전

	std::cout << menu;
}


