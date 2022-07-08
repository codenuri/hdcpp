// 6_cout - 187page
//#include <iostream>
#include <cstdio>

namespace std
{
	class ostream
	{
	public:
		// 주의 : 반환 타입은 "ostream" 이 아니라 "ostream&" 이어야 합니다
		// => 이유는 "임시객체" 수업 참고.. 
		ostream& operator<<(int n)    { printf("%d", n); return *this; }
		ostream& operator<<(double d) { printf("%lf", d); return *this;}
		ostream& operator<<(const char* s) { printf("%s", s); return *this;}
	};
	ostream cout;  
}

int main()
{
	std::cout << "A" << "B" << "C";
	// cout.operator<<("A").operator<<("B").operator<<("C")


	int    n = 10;
	double d = 3.4;

	std::cout << n;  
	std::cout << d;  
}


