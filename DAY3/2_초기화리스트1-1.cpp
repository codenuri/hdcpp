// 6_초기화리스트1    85page ~
#include <iostream>
#include <string>

class Person
{
	std::string name;
	int age;
public:
	// 핵심 : 초기화 vs 대입
	Person(const std::string& n, int a) : name(n), age(a) // 초기화입니다.
	{
		name = n; // 이건 초기화가 아닙니다. 대입 입니다.
		age = a;
	}
};

int main()
{
	Person p1("kim", 10);

	// 초기화 vs 대입
	// primitive 타입의 경우 : 초기화 와 대입은 유사한 기계어 코드가 생성됩니다.
	int a = 10;		// 초기화(만들면서 넣는것)
	int b;
	b = 10;			// 대입(만든후에 넣는것)

	// user 타입의 경우는 아래와 같은 차이점이 있습니다.
	std::string s1("hello"); // 초기화
							 // 인자가 한개인 생성자 호출로 "hello" 보관!
							 // 즉, 한번의 함수 호출로 초기화 완료!

	std::string s2;			// 1. 디폴트 생성자 호출
	s2 = "hello"; // 대입	// 2. 대입연산자 호출(s2.operator=("hello"))
							// 즉, 2회의 함수 호출로 "hello" 보관
}







