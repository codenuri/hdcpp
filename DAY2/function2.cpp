#include <iostream>
#include <functional>
using namespace std::placeholders;

void f1(int a)               { printf("f1 : %d\n", a); }
void f2(int a, int b)        { printf("f2 : %d, %d\n", a, b);}
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d);}

class Dialog
{
public:
	void Init(int a, int b)
	{
		printf("Dialog Init : %d, %d\n", a, b);
	}
};

int main()
{
	// C 언어의 함수 포인터는 한계가 있습니다.
	// => signature(반환타입과 인자)가 동일한 함수 주소만 담을수 있습니다.
//	void(*f)(int);
//	f = &f1; // ok
//	f = &f2; // error.

	// C++ 의 std::function 은 함수 포인터를 발전시킨 타입 입니다.
	// 사용법 : std::function<함수타입>
	// 함수 타입       : void(int)
	// 함수 포인터 타입 : void(*)(int)

	std::function<void(int)> f;
	f = &f1;
	f(10); // f1(10);

//	f = &f2; // error. f2 는 인자가 2개


	// 하지만 std::function 은 std::bind 의 반환값 보관은 가능
	f = std::bind(&f2, _1, 0);
	f(10); // f2(10, 0);
}










