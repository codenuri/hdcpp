#include <functional>

void foo(int a) {}

class Sample 
{
public:	
	void goo(int a) {}
};

int main()
{
	void(*f1)(int) = &foo;
//	void(*f2)(int) = &Sample::goo; // error. 함수 포인터에 멤버함수주소
									//		담을수 없습니다.

	// 핵심 #1. 멤버 함수의 주소를 담는 함수 포인터 만들기.
	void(Sample::*f2)(int) = &Sample::goo; // ok				

	// 핵심 #2. 멤버 함수포인터 사용하기
	f2(10); // error. 객체가 없다.
	
	Sample s;
//	s.f2(10); // error. sample 에는 f2 멤버 함수 없다.
			  // f2 는 멤버함수이름이 아닌, 함수 포인터

	// 핵심 #3. .* 연산자 이해 - pointer to member operator
	//			".*" 가 하나의 연산자
	//s.*f2(10); // 연산자 우선순위 문제로 에러
	(s.*f2)(10); // ok. 멤버 함수 포인터로 함수 호출하기

	// 핵심 #4. 동일하게 호출할수 없을까 ?
	f1(10);       // 일반 함수포인터로 호출
	(s.*f2)(10);  // 멤버 함수포인터로 호출

	// std::invoke 의 의미
	// => 모든 호출 가능한 요소로 호출시 동일한 방식으로 표기
	// => 멤버 함수는 2번째 인자로 객체를
	std::invoke(f1, 10);			// f1(10)	
	std::invoke(f2, &s, 10);		// (s.*f2)(10)

}
