#include <iostream>
#include <string>

// 자동 생성 규칙.

// 규칙 #2


struct Object
{
	std::string name;
	Object(const std::string& n) : name(n) {}

	// 사용자가 복사생성자만 만든경우
	Object(const Object& obj) : name{obj.name} 
	{
		std::cout << "사용자가 만든 복사생성자\n";
	}
};


int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;				
	Object o4 = std::move(o2);	

	std::cout << o1.name << std::endl; 
	std::cout << o2.name << std::endl; 
}
