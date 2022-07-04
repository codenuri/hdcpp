#include <cstdio>
// 4_함수2 - 28 page 함수 오버로딩 

// 핵심 : 인자의 갯수나 타입이 다르면 동일이름의 함수를 2개이상
//		 만들수 있다.
//       "function overloading 문법" - C++98
//       거의 모든 언어가 지원
// 지원되지 않은 언어 : C언어, Python 

int square(int a)
{
	return a * a;
}
double square(double a)
{
	return a * a;
}
int main()
{
	// C/C++에서 모든 것은 타입이 있습니다
	// 3   : int
	// 3.3 : double
	// 2.3f : float 등..
	// 그래서 컴파일러는 인자를 보고, 어느 함수 인지 구별할수 있습니다.
	square(3);
	square(3.4);
}
// 주의 사항.
// 컴파일시간에 어느 함수 인지 구별 가능해야 합니다.
void f1(int) {}
char f1(int) {}

f1(3);

void f2(int a) {}
void f2(int a, int b = 0) {}
f2(0);


