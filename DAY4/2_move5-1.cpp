#include <iostream>
#include <string>

// 자동 생성 규칙.

// 규칙 #2. 사용자가 복사 생성자만 만들면
// => 컴파일러는 이동생성자 제공안함.
// => std::move() 사용시, 에러가 아니라 "사용자가 복사 생성자" 호출

// => 컴파일러에게 "이동생성자" 를 만들어 달라고 하려면
//    "= default" 문법 사용


struct Object
{
	std::string name;
	Object(const std::string& n) : name(n) {}

	// 사용자가 복사생성자만 만든경우
	Object(const Object& obj) : name{obj.name} 
	{
		std::cout << "사용자가 만든 복사생성자\n";
	}

	// 컴파일러에게 이동생성자를 만들어달라고 요청하는 것
	Object(Object&&) = default;

};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;				// 사용자 복사 생성자 호출
	Object o4 = std::move(o2);	// 사용자 복사 생성자 호출
								// 단, "= default" 가 있으면
								// 이동생성자 호출

	std::cout << o1.name << std::endl; 
	std::cout << o2.name << std::endl; 
}
