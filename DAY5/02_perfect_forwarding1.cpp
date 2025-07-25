#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// perfect forwarding 이란 ?
// => 전달 받은 인자를 어떠한 변화도 없이 다른 함수에게 완벽히 전달하는것
// => "값, 상수성, value 속성, 타입"등 모든 정보에 변경없이 전달

// => 아래 코드는 "인자의 복사본"이 생성되므로 "완벽한 전달이 될수 없습니다."
//    goo 에 다시 전달시 "복사본 전달"

// 성능을 측정하는 함수
template<typename F, typename T>
void chronometry(F f, T arg)
{
	// <========== 시간을 기록하고
	f(arg); //     함수 호출
	// <========== 수행시간 출력
}
int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10);
	chronometry(goo, n);  // goo(n);

	std::cout << n << std::endl;
}
