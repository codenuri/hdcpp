// 4_함수4-1
#include <iostream>

// 아래 square는 
// 1. 함수가 아닙니다. 
// 2. 함수를 찍어낼때 사용하는 "틀(템플릿)" 입니다. "함수템플릿"이라고 부릅니다.
// 3. 틀은 "컴파일 시간"에만 사용됩니다. "틀의 주소"라는 개념은 없습니다.

template<typename T>
T square(T a)
{
	return a * a;
}

int main()
{
//	square<int>(3);
//	printf("%p\n", &square); // error. 함수의 틀은 주소가 없습니다.
	printf("%p\n", &square<int> );	// square<int> 가 필요하다고 생각해서
									// square<int> 함수를 생성
									// 그리고, 생성된 함수의 주소를 출력

}
// 요즘 C++을 정의 하면
// "C언어 + 객체지향프로그래밍 + Generic(일반화) 프로그래밍(template문법)"