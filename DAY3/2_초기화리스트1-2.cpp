// 6_초기화리스트1    85page ~
#include <iostream>
#include <string>

class Person1
{
	std::string name;
	int age;
public:
	// 사용자 코드						// 컴파일러가 추가한 코드
	Person1(const std::string& n, int a)// : name()   <== 1. 디폴트 생성자 호출
	{
		name = n;	// 2. name.operator=(n) 즉, 대입연산자 호출
					// 결국, 2회의 함수 호출을 통해서 값을 넣은것
		age = a;
	}
};

class Person2
{
	std::string name;
	int age;
public:
	// 아래 코드는 초기화 리스트에서 "name"의 생성자를 호출하는 코드를
	// 사용자가 제공했으므로 컴파일러는 위 "Person1" 처럼 추가하는 코드 없습니다.
	Person2(const std::string& n, int a) : name(n), age(a)
	{
	}
};
int main()
{
	Person1 p1("kim", 10); // call Person1::Person1()

	Person2 p2("kim", 10); // call Person2::Person2()
}
// godbolt.org 를 통해서 정확히 확인 가능합니다.
// 그런데,
// std::string 의 진짜 클래스 이름은 "std::basic_string" 입니다.
// 사용하기 쉽게 하려고 "std::string" 이라는 별명을 사용하고 있는 것 입니다.
//using string = std::basic_string<char, charTraits, std::allocator<char>>;






