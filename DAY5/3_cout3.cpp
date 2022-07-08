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

		ostream& operator<<(ostream&(*f)(ostream&) )
		{ 
			// 아래 한줄이 핵심입니다.
			// => 인자로 전달받은 함수를 호출하면서 "자신(cout)"을 전달하는것
		//	f(*this);   // endl(cout)
		//	return *this; 

			return f(*this); // 이렇게 하세요..
		}
	};
	ostream cout;

	ostream& endl(ostream& os)
	{
		os << "\n";
		return os;
	}
}
int main()
{
	// std::endl 의 정체는 함수 입니다.
	std::endl( std::cout ); // 이 코드와 위 코드는 동일 합니다.

	// 아래 코드의 원리가 중요 합니다
	std::cout << std::endl; // cout.operator<<( endl)
						    // cout.operator<<( 함수포인터)
							// cout.operator<<( ostream&(*)(ostream&) )
}


