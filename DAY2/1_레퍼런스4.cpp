// 1_레퍼런스4.   100 page
#include <iostream>
int x = 0;
int  foo() { return x; }  // x의 값(0) 을 반환
int& goo() { return x; }  // x의 별명을 반환

int main()
{
	int v1 = 10, v2 = 20;

	v1 = 20; // v1 등호의 왼쪽   : v1의 메모리 정보(주소)를 가져오는 기계어코드
	v2 = v1; // v1 등호의 오른쪽 : v1의 값(10)을 가져오는 기계어 코드

//	foo() = 20; // error. 0 = 20 의 의미
	goo() = 20; // ok..   x = 20 의 의미와 동일

	std::cout << x << std::endl; // 20
}

// 핵심 : 함수가 reference를 반환하면 
//       "함수 호출"을 "등호의 왼쪽" 에 놓을수 있습니다.
//       "goo() = 20" 이 가능