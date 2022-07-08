#include <iostream>

// 객체 지향 언어에서의 "함수 실패 처리 방법"
// => "예외" 라는 것은 "던집니다.(throw)"

int f1()
{
	if (1)			// 실패라고 가정
		throw 1;	// 실패시 예외를 던진다

	return 100;
}

int main()
{
	int ret = f1();
}
