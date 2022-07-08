#include <iostream>

// 객체 지향 언어에서의 "함수 실패 처리 방법"
// => "예외" 라는 것은 "던집니다.(throw)"

// => 호출자는 던져진 예외를 처리하지 않으면 프로그램이 비정상종료 된다.
// => 즉, 던져진 예외는 반드시 처리되어야 한다.
int f1()
{
	if (1)			// 실패라고 가정
		throw 1;	// 실패시 예외를 던진다

	return 100;
}

int main()
{
	int ret = f1();

	std::cout << "main 계속 실행" << std::endl;
}
