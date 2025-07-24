#include <iostream>
#include <string>

// 자동 생성 규칙.

// 규칙 #3. 사용자가 이동 생성자만 만들때
// => 컴파일러는 "복사생성자" 제공 안함
// => 복사가 필요한 코드는 에러

// => 복사 생성자의 디폴트 버전이 필요하면 "= default" 로 요청

// 권장
// #1. 최선의 코드 "복사생성자/이동생성자" 모두 만들지 말라
// #2. 만들려면 모두 만들어라
// "all or nothing"



struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {}

	// 사용자가 만든 이동 생성자
	Object(Object&& obj) : name{ std::move(obj.name) }
	{
		std::cout << "사용자가 만든 이동생성자\n";
	}
};
int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;				// 컴파일 에러	
	Object o4 = std::move(o2); // 사용자가 만든 이동 생성자 호출

	std::cout << o1.name << std::endl; 
	std::cout << o2.name << std::endl; 
}
