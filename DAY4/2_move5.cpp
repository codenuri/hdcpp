#include <iostream>
#include <string>

// 자동 생성 규칙.

// 규칙 #1. 사용자가 복사생성자/이동생성자를 모두 만들지 않으면 
// => 컴파일러가 모두 제공한다.
// => 복사와 이동을 지원하는 완벽한 클래스


struct Object
{
	std::string name;

	// 일반 생성자
	Object(const std::string& n) : name(n) {}
};


int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;				// 디폴트 복사 생성자 - 모든 멤버 복사
	Object o4 = std::move(o2);	// 디폴트 이동 생성자 - 모든 멤버 이동

	std::cout << o1.name << std::endl; // "obj1"
	std::cout << o2.name << std::endl; // ""
}
