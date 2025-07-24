#include <iostream>
#include <cstring>

// 클래스가 포인터 멤버 있다면
// => 컴파일러 제공 복사 생성자는 "얕은 복사" 현상있습니다.
// => 반드시 복사 생성자 만들어야 합니다.
// => 이때 이동을 지원하려면 "이동생성자" 만들어야 합니다.
// => 즉, 다 만들어야 합니다.


// char* 대신 std::String 을 사용했다면
// => 사용자가 자원 관리할 필요 없다.
// => 복사/이동 모두 만들필요 없다.
// => 아무것도 만들지 않으면 컴파일러가 모두 지원!!!

// 즉, 아래 코드는 "복사 와 이동"을 지원하는 완벽한 코드!!!

// 권장
// => 자원을 직접 관리하지 말고, 자원 관리 클래스를 사용하세요
// char* => std::string
// int*  => std::vector<int>, smart_pointer

class Cat
{
	std::string name;
	int   age;
public:
	Cat(const std::string& n, int a) : name{n}, age{a}
	{
	}
};

int main()
{
	Cat c1{"nabi", 2};

	Cat c2 = c1; 	
	Cat c3 = std::move(c2); 
}
