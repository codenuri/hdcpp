// 6_cout - 187page
//#include <iostream>
#include <cstdio>

// cout 의 원리
namespace std
{
	class ostream
	{
	public:
		// 실제 출력은 "OS들이 제공하는 system call" 을 사용합니다.
		// 아래 3개 뿐 아니라.. 
		// 모든 표준 타입에 대해서 "operator<<" 를 제공하고 있습니다.
		void operator<<(int n)    { printf("%d", n); }
		void operator<<(double d) { printf("%lf", d); }
		void operator<<(const char* s) { printf("%s", s); }
	};
	ostream cout;  // cout 은 결국 전역변수(ostream 타입의 객체) 입니다.
}
int main()
{
	int    n = 10;
	double d = 3.4;

	std::cout << n;  // cout.operator<<(int)
	std::cout << d;  // cout.operator<<(double)
}


