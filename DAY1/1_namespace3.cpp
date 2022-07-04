// 1_namespace3.cpp - 9page 내용
// 
#include <algorithm>
using namespace std; // 모든 표준을 "std" 이름 공간없이 사용하겠다는 것

// 핵심 1. 모든 C++ 표준은 "std" 라는 이름 공간에 있습니다.

int count = 10;

int main()
{
	int n2 = count; // 왜 컴파일 에러일까요 ?
					// 에러메세지 확인해 보세요.
					// C++ 표준에 "std::count()" 가 있습니다.
					// std 이름공간을 열어놓아서
					// 전역변수와 표준 함수 의 이름 충돌 발생


//	int n = min(3, 2); // C++ 표준 함수. algorithm 헤더 필요

	int n = std::min(3, 2); // ok. 모든 표준 함수는 std 안에 있다.
}
